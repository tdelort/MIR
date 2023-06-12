#pragma once

#include "core.h"

#include <string>
#include <string_view>
#include <stdexcept>

namespace mir
{
	class debug
	{
		class assert_error : public std::runtime_error
		{
		public:
			assert_error(std::string const & _message);
		};

	public:
		enum class LogLevel : uint8_t
		{
			Debug,
			Log,
			Warn,
			Error
		};
		static void assert( bool _condition, std::string_view const _message, const char* _file, const char* _function, int _line );
		static void print(LogLevel _level, std::string_view const _message, const char* _file, const char* _function, int _line );
	};
} // namespace mir


#define MIR_BREAKPOINT __debugbreak()
#define MIR_PRETTY_FUNCTION __FUNCTION__

#define MIR_ASSERT(_test, _msg) MIR_MAKE_STMT(debug::assert( (_test), (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)

#define MIR_LOG_ERROR(_msg) MIR_MAKE_STMT(debug::print(debug::LogLevel::Error, (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__); MIR_BREAKPOINT;)
#define MIR_LOG_WARNING(_msg) MIR_MAKE_STMT(debug::print(debug::LogLevel::Warn, (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)
#define MIR_LOG_DEBUG(_msg) MIR_MAKE_STMT(debug::print(debug::LogLevel::Debug , (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)
#define MIR_LOG(_msg) MIR_MAKE_STMT(debug::print(debug::LogLevel::Log, (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)
