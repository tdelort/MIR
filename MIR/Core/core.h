#ifndef CORE_CORE_H_INCLUDED
#define CORE_CORE_H_INCLUDED

#define MIR_MAKE_STMT(_expr) do { _expr } while(0)
#define MIR_FLOAT_EPSILON FLT_EPSILON
#define MIR_DLLEXPORT __declspec(dllexport)

#if defined( _WIN32 )
#define MIR_OS_WINDOWS

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <wrl.h>

#endif // defined( _WIN32 )

#endif // CORE_CORE_H_INCLUDED
