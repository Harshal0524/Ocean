#pragma once

#include <spdlog/spdlog.h>

namespace Ocean 
{
    class Log 
    {
    public:
        static void Init();
        
        static std::shared_ptr<spdlog::logger>& GetEngineLogger() {
            return s_EngineLogger;
        };

        static std::shared_ptr<spdlog::logger>& GetClientLogger() {
            return s_ClientLogger;
        };

        static void Shutdown();
    private:
    // Seperate core and clent logging
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}
