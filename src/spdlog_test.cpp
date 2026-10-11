#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog_test.h"

namespace spdlog_test
{
    /* Basic usage */
    void spdlog_test_Basic_usage()
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

    /* Create stdout/stderr logger object */
    void spdlog_test_Create_stdout_stderr_logger_object()
    {
        // create a color multi-threaded logger
        auto console = spdlog::stdout_color_mt("console");
        auto err_logger = spdlog::stderr_color_mt("stderr");
        spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
        spdlog::get("stderr")->trace("logger [stderr] level_1 is trace.");
        spdlog::get("stderr")->set_level(spdlog::level::trace);
        spdlog::get("stderr")->trace("logger [stderr] level_2 is trace.");
        spdlog::get("console")->trace("logger [console] level_1 is trace.");
    }

} // namespace spdlog_test