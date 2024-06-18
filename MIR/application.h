#ifndef CORE_APPLICATION_H_INCLUDED
#define CORE_APPLICATION_H_INCLUDED

#include "Core/core.h"

namespace mir
{
	class MIR_DLLEXPORT application
	{
	public:
		application();
		~application();

		int run();
	};
}

#endif // !CORE_APPLICATION_H_INCLUDED
