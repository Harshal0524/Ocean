#include "Ocean/Core.h"

#include <vector>

#include "spdlog/sinks/stdout_color_sinks.h"


namespace Ocean {

    std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        //setting a patten [mm-dd-yyyy hh:mm:ss.mm err_loged]
        spdlog::set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] %n: %v%$");

        //this creates a shared pointer to a object and the heap auto cleans up when neathing else holds refreances to it
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(consoleSink);

        // Engine Logger for engine level logs
        s_EngineLogger = std::make_shared <spdlog::logger> (
            OCEAN_DEFAULT_ENGINE_LOGGER_NAME, 
            sinks.begin(), 
            sinks.end());
        s_EngineLogger->set_level(spdlog::level::trace);
        s_EngineLogger->flush_on(spdlog::level::trace);
        spdlog::register_logger(s_EngineLogger);
        
        // Cient logger for game build in engine logs
        s_ClientLogger = std::make_shared <spdlog::logger> (
            OCEAN_DEFAULT_CLIENT_LOGGER_NAME, 
            sinks.begin(), 
            sinks.end());
        s_ClientLogger->set_level(spdlog::level::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);
        spdlog::register_logger(s_ClientLogger);
    }

    void Log::Shutdown()
    {
        spdlog::shutdown();
        s_EngineLogger.reset();
        s_ClientLogger.reset();
    }
}