#include "pch.h"
#include "dx12_pch.h"
#include "dx12_render_device.h"

using namespace Microsoft::WRL;

namespace mir
{
	void enable_debug_layer()
	{
#if defined(_DEBUG)
		// Always enable the debug layer before doing anything DX12 related
		// so all possible errors generated while creating DX12 objects
		// are caught by the debug layer.
		ComPtr<ID3D12Debug> debugInterface;
		// TODO ASSERT
		D3D12GetDebugInterface(IID_PPV_ARGS(&debugInterface));
		debugInterface->EnableDebugLayer();
#endif
	}

	
}
