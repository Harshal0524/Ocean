#pragma once

#include "Ocean/Log.h"
#include "Ocean/Application.h"
#include "Ocean/Core.h"

int main(int argc, char** argv) {
    Ocean::Log::Init();
    
    //OCEAN_INFO("Test for client log!!");
    OCEAN_CORE_INFO("Engine log Initialized");

    auto app = Ocean::CreateApplication();

    app-> Run();

    delete app;

    Ocean::Log::Shutdown();

    return 0;
}