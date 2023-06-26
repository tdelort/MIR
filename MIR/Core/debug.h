#pragma once

#include "core.h"

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
		enum class log_level : uint8_t
		{
			debug,
			log,
			warn,
			error
		};
		static void assert( bool _condition, std::string_view const _message, const char* _file, const char* _function, int _line );
		static void print(log_level _level, std::string_view const _message, const char* _file, const char* _function, int _line );
	};
} // namespace mir


#define MIR_BREAKPOINT __debugbreak()
#define MIR_PRETTY_FUNCTION __FUNCTION__

#define MIR_ASSERT(_test, _msg) MIR_MAKE_STMT(debug::assert( (_test), (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)

#define MIR_LOG_ERROR(_msg) MIR_MAKE_STMT(debug::print(debug::log_level::error, (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__); MIR_BREAKPOINT;)
#define MIR_LOG_WARNING(_msg) MIR_MAKE_STMT(debug::print(debug::log_level::warn, (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)
#define MIR_LOG_DEBUG(_msg) MIR_MAKE_STMT(debug::print(debug::log_level::debug , (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)
#define MIR_LOG(_msg) MIR_MAKE_STMT(debug::print(debug::log_level::log, (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)
