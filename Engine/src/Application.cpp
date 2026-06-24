#include <iostream>
#include "/home/Neo/GameEngine/Ocean/Engine/include/Ocean/Application.h"
#include <spdlog/spdlog.h>

namespace Ocean {
    void Application::Run() {
        std::cout << "Ocean Engine running!" << std::endl;
        spdlog::info("splog is linked and working");
    }
}