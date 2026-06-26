#pragma once

#include <spdlog/spdlog.h>

namespace Ocean 
{
    class Log 
    {
    public:
        static void Init();
        
        static std::shared_ptr<spdlog::logger>& GetLogger() {
            return s_Logger;
        };

        static void Shutdown();
    private:
    // Seperate core and clent logging TODO
        static std::shared_ptr<spdlog::logger> s_Logger;
    };
}
