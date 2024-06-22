#ifndef DISPLAY_RENDERING_SERVICE_H_INCLUDED
#define DISPLAY_RENDERING_SERVICE_H_INCLUDED

#include "Core/service.h"

namespace mir
{
	class rendering_service : public service_interface
	{
	public:
		virtual ~rendering_service() = 0 {};
	};
}

#endif // DISPLAY_RENDERING_SYSTEM_H_INCLUDED
