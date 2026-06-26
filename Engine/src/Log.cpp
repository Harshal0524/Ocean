#include "Ocean/Core.h"

#include <vector>

#include "spdlog/sinks/stdout_color_sinks.h"


namespace Ocean {

    std::shared_ptr<spdlog::logger> Log::s_Logger;

    void Log::Init()
    {
        //this creates a shared pointer to a object and the heap auto cleans up when neathing else holds refreances to it
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        //setting a patten [mm-dd-yyyy hh:mm:ss.mm err_loged]
        consoleSink->set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] %v%$");

        //std::vector<spdlog::sink_ptr> sinks = ( consoleSink );
        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(consoleSink);
        s_Logger = std::make_shared <spdlog::logger> (
            OCEAN_DEFAULT_LOGGER_NAME, 
            sinks.begin(), 
            sinks.end());
        
        s_Logger->set_level(spdlog::level::trace);
        s_Logger->flush_on(spdlog::level::trace);
        spdlog::register_logger(s_Logger);
    }

    void Log::Shutdown()
    {
        spdlog::shutdown();
        s_Logger.reset();
    }
}