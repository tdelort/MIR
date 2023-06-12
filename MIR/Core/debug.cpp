#include "debug.h"

#include <string>
#include <string_view>
#include <iostream>

namespace mir
{
    debug::assert_error::assert_error(std::string const & _message)
        : std::runtime_error("mir::utils::assert_error(" + _message + ")")
    { }

    void debug::assert(bool _condition, std::string_view const _message, const char* _file, const char* _function, int _line )
    {
        if(!_condition)
        {
            print(LogLevel::Error, _message, _file, _function, _line);
            throw assert_error(_message.data());
        }
    }

	void debug::print(LogLevel _level, std::string_view const _message, const char* _file, const char* _function, int _line )
    {
        std::ostream& os = _level == LogLevel::Error ? std::cerr : std::cout;
        
        // set the color of the text
        std::string prefix;
        switch(_level)
        {
            case LogLevel::Debug:
                prefix = "\033[0;37m[DEBUG] ";
                break;
            case LogLevel::Warn:
                prefix = "\033[0;33m[WARN] ";
                break;
            case LogLevel::Error:
                prefix = "\033[0;31m[ERROR] ";
                break;
            default:
                prefix = "\033[0;36m[LOG] ";
        }

        os << prefix << _file << ":" << _line << " in " << _function << " : " << _message << "\033[0m" << std::endl;
    }
} // namespace mir