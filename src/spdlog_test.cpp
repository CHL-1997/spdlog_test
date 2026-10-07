#include "spdlog/spdlog.h"
#include "spdlog_test.h"

namespace spdlog_test
{
    /* Basic usage */
    void spdlog_test_basic_usage()
    {
        spdlog::info("Welcome to spdlog!");
        spdlog::error("Some error message with arg: {}", 1);

        spdlog::warn("Easy padding in numbers like {:08d}", 12);
        spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
        spdlog::info("Support for floats {:03.2f}", 1.23456);
        spdlog::info("Positional args are {1} {0}..", "too", "supported");
        spdlog::info("{:<30}", "left aligned");

        /* 默认是 SPDLOG_LEVEL_INFO 等级，下面这两句不会打印 */
        spdlog::trace("this is [trace] level!");
        spdlog::debug("this is [debug] level!");

        spdlog::set_level(spdlog::level::debug); // Set *global* log level to debug
        spdlog::debug("This message should be displayed..");

        // change log pattern
        spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

        // Compile time log levels
        // Note that this does not change the current log level, it will only
        // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
        SPDLOG_TRACE("Some trace message with param {}", 42);
        SPDLOG_DEBUG("Some debug message");
        SPDLOG_INFO("Some info message with param {}", 42);
        SPDLOG_WARN("Some warm message");
    }

} // namespace spdlog_test