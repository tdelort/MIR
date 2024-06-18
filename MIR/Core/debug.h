#ifndef CORE_DEBUG_H_INCLUDED
#define CORE_DEBUG_H_INCLUDED

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
		static void assert_if( bool _condition, std::string_view const _message , const char* _file, const char* _function, int _line );
		static void print( log_level _level, std::string_view const _message , const char* _file, const char* _function, int _line );
	};
} // namespace mir


#define MIR_BREAKPOINT __debugbreak()
#define MIR_PRETTY_FUNCTION __FUNCTION__


#define MIR_ASSERT(_test, _msg) MIR_MAKE_STMT(debug::assert_if( (_test), (_msg), __FILE__, MIR_PRETTY_FUNCTION, __LINE__);)

#define MIR_LOG_INTERNAL( _level, _msg )	\
{											\
	std::stringstream MIR_LOG_INTERNAL__ss;	\
	MIR_LOG_INTERNAL__ss << _msg;			\
	debug::print( _level, MIR_LOG_INTERNAL__ss.str(), __FILE__, MIR_PRETTY_FUNCTION, __LINE__ ); \
}

#define MIR_LOG_ERROR(_msg) MIR_LOG_INTERNAL(debug::log_level::error, _msg );
#define MIR_LOG_WARNING(_msg) MIR_LOG_INTERNAL(debug::log_level::warn, _msg );
#define MIR_LOG(_msg) MIR_LOG_INTERNAL(debug::log_level::log, _msg );
#define MIR_LOG_DEBUG(_msg) MIR_LOG_INTERNAL(debug::log_level::debug, _msg );

#endif // CORE_DEBUG_H_INCLUDED
