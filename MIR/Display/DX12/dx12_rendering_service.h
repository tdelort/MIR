#ifndef DISPLAY_DX12_DX12_RENDERING_SERVICE_H_INCLUDED
#define DISPLAY_DX12_DX12_RENDERING_SERVICE_H_INCLUDED

#include <Core/service.h>
#include <Display/rendering_service.h>

namespace mir
{
	class dx12_rendering_service : public service_generic<rendering_service>
	{
		dx12_rendering_service();
	};
}

#endif // DISPLAY_DX12_DX12_RENDERING_SERVICE_H_INCLUDED
