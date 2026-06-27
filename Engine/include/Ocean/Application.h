#pragma once

#include "Ocean/Core.h"
#include "Ocean/Log.h"

namespace Ocean {

    class Application {
    public:
        virtual ~Application() = default;
        void Run();
    };

    Application* CreateApplication();
}