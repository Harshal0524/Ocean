#include <iostream>
#include "Ocean/Application.h"
#include "Ocean/Core.h"
#include <spdlog/spdlog.h>

namespace Ocean {
    void Application::Run() {
        std::cout << "Ocean Engine running!" << std::endl;
        OCEAN_INFO("Looging macros are working");
    }
}