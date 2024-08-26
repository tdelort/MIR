#ifndef DISPLAY_DX12_DX12_RENDER_DEVICE_H_INCLUDED
#define DISPLAY_DX12_DX12_RENDER_DEVICE_H_INCLUDED

#include "dx12_pch.h"

#include <Display/render_device.h>
#include <Display/command_buffer.h>
#include <Display/window.h>

#include <Display/DX12/dx12_command_queue.h>

namespace mir
{
	class swap_chain;

	class dx12_render_device : public render_device
	{
	public:
		dx12_render_device( ComPtr<IDXGIFactory4>& _factory_handle );

		ID3D12Device2* get_api_handle() const;

		command_queue& get_command_queue(command_buffer::type _corresponding_command_buffer_type) override;

		// factory part
		std::unique_ptr<swap_chain> create_swap_chain(rendering_service& _render_service, window& _window, vec2u _size) override;
	private:
		std::unique_ptr<dx12_command_queue> m_graphics_queue;

		ComPtr<ID3D12Device2> m_api_device_handle;
#if defined(_DEBUG)
		ComPtr<ID3D12InfoQueue> m_info_queue;
#endif // defined(_DEBUG)
	};
}

#endif // DISPLAY_DX12_DX12_RENDER_DEVICE_H_INCLUDED
