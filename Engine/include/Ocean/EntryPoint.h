#pragma once

#include "Ocean/Log.h"
#include "Ocean/Application.h"
#include "Ocean/Core.h"

int main() {
    Ocean::Log::Init();
    //TODO Fix the mactos for engine and client
    //OCEAN_INFO("works!!");
    //OCEAN_CORE_INFO("Engine is init");

    auto app = Ocean::CreateApplication();

    app-> Run();

    delete app;

    Ocean::Log::Shutdown();

    return 0;
}