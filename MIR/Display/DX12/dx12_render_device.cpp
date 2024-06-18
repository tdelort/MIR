#include "pch.h"
#include "dx12_pch.h"
#include "dx12_render_device.h"

using namespace Microsoft::WRL;

namespace mir
{
	dx12_render_device::dx12_render_device()
	{
		ComPtr<IDXGIFactory4> dxgiFactory;
		HRESULT hr = CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory));
		if (FAILED(hr))
		{
			// Error!
		}

		ComPtr<IDXGIAdapter1> adapter;
		for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != dxgiFactory->EnumAdapters1(adapterIndex, &adapter); ++adapterIndex)
		{
			DXGI_ADAPTER_DESC1 desc;
			hr = adapter->GetDesc1(&desc);
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
	}

}
