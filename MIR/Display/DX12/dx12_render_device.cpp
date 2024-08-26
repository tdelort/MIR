#include "dx12_pch.h"
#include "dx12_render_device.h"

#include <Display/command_buffer.h>
#include <Display/DX12/dx12_command_buffer.h>

#include <Display/window.h>

#include <Display/swap_chain.h>
#include <Display/DX12/dx12_swap_chain.h>

#include <Display/DX12/dx12_command_queue.h>

#include <Display/rendering_service.h>
#include <Display/DX12/dx12_rendering_service.h>

namespace mir
{
	dx12_render_device::dx12_render_device( ComPtr<IDXGIFactory4>& _factory_handle )
	{
		ComPtr<IDXGIAdapter1> adapter;
		for (UINT adapter_index = 0; DXGI_ERROR_NOT_FOUND != _factory_handle->EnumAdapters1(adapter_index, &adapter); ++adapter_index)
		{
#if defined(_DEBUG)
			ComPtr<ID3D12Debug> debug_interface;

			D3D12GetDebugInterface(IID_PPV_ARGS(&debug_interface));
			debug_interface->EnableDebugLayer();
#endif // defined(_DEBUG)

			DXGI_ADAPTER_DESC1 desc;
			HRESULT hr = adapter->GetDesc1(&desc);
			if (FAILED(hr))
				continue;

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{
				// Don't select the Basic Render Driver adapter.
				continue;
			}

			// Check to see if the adapter supports Direct3D 12,
			// but don't create the actual device yet.
			if (SUCCEEDED(
				D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0,
					_uuidof(ID3D12Device), nullptr)))
			{
				break;
			}
		}

		ComPtr<ID3D12Device2> d3d12_device_2;
		HRESULT hr = D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&d3d12_device_2));
		MIR_ASSERT(SUCCEEDED(hr), "Failed to create D3D12 Device (" << hr << ")");

#if defined(_DEBUG)
		if (SUCCEEDED(d3d12_device_2.As(&m_info_queue)))
		{
			m_info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE);
			m_info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, TRUE);
			m_info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, TRUE);
	 
			D3D12_INFO_QUEUE_FILTER info_queue_filter = {};
#if 0
			// Suppress whole categories of messages
			D3D12_MESSAGE_CATEGORY categories[] = {};
			info_queue_filter.DenyList.NumCategories = _countof(categories);
			info_queue_filter.DenyList.pCategoryList = categories;
#endif // 0

#if 0
			// Suppress messages based on their severity level
			D3D12_MESSAGE_SEVERITY severities[] =
			{
				D3D12_MESSAGE_SEVERITY_INFO
			};
			info_queue_filter.DenyList.NumSeverities = _countof(severities);
			info_queue_filter.DenyList.pSeverityList = severities;
#endif // 0

#if 0
			// Suppress individual messages by their ID
			D3D12_MESSAGE_ID deny_ids[] = {
				D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE,   // I'm really not sure how to avoid this message.
				D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE,                         // This warning occurs when using capture frame while graphics debugging.
				D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE,                       // This warning occurs when using capture frame while graphics debugging.
			};
			info_queue_filter.DenyList.NumIDs = _countof(deny_ids);
			info_queue_filter.DenyList.pIDList = deny_ids;
#endif // 0
	 
			HRESULT hr = m_info_queue->PushStorageFilter(&info_queue_filter);
			MIR_ASSERT(SUCCEEDED(hr), "An error occurend when pushing storage filter in info queue (" << hr << ")");
		}
#endif // defined(_DEBUG)

		m_api_device_handle = d3d12_device_2;

		// Now create needed command queues

		m_graphics_queue = std::make_unique<dx12_command_queue>(*this, command_buffer::type::Graphics);
		//m_compute_queue = std::unique_ptr<dx12_command_queue>(new dx12_command_queue( this, command_buffer::type::Compute ));
		//m_copy_queue = std::unique_ptr<dx12_command_queue>(new dx12_command_queue( this, command_buffer::type::Copy ));
	}

	command_queue& dx12_render_device::get_command_queue(command_buffer::type _corresponding_command_buffer_type)
	{
		// TODO use arg when supporting more queues
		(void)_corresponding_command_buffer_type;

		return *m_graphics_queue.get();
	}

	std::unique_ptr<swap_chain> dx12_render_device::create_swap_chain(rendering_service& _render_service, window& _window, vec2u _size)
	{
		return std::make_unique<dx12_swap_chain>(static_cast<dx12_rendering_service&>(_render_service), _window, _size);
	}

	ID3D12Device2* dx12_render_device::get_api_handle() const
	{
		return m_api_device_handle.Get();
	}
}
