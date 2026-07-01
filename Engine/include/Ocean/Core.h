#pragma once

#include "Ocean/Log.h"
#include "spdlog/spdlog.h"

//------------------- Cross-Platform Support ----------------
#ifdef _WIN32
    #define OCEAN_PLATFORM_WINDOWS
#elif defined(__APPLE__)
    #define OCEAN_PLATFORM_MACOS
#elif defined(__linux__)
    #define OCEAN_PLATFORM_LINUX
#else
    #error Unsuppoeted platform
#endif

// DLL export macro
#ifdef OCEAN_PLATFORM_WINDOWS
    #ifdef OCEAN_BUILD_DLL
        #define OCEAN_API __declspec(dllexport)
    #else
        #define OCEAN_API __declspec(dllimport)
    #endif
#else
    #define OCEAN_API
#endif
// ---------------------------------------------------------

// ---------------------- Logging macros --------------------
#define OCEAN_DEFAULT_ENGINE_LOGGER_NAME "OceanEnginelogger"
#define OCEAN_DEFAULT_CLIENT_LOGGER_NAME "OceanClientlogger"

#ifndef OCEAN_CONFIG_RELEASE

    //Engine Logs
    #define OCEAN_CORE_TRACE(...)     if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> trace(__VA_ARGS__))
    #define OCEAN_CORE_INFO(...)      if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> info(__VA_ARGS__))
    #define OCEAN_CORE_DEBUG(...)     if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> debug(__VA_ARGS__))
    #define OCEAN_CORE_WARN(...)      if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> warn(__VA__ARGS__))
    #define OCEAN_CORE_ERROR(...)     if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> error(__VA_ARGS__))
    #define OCEAN_CORE_CRITICAL(...)  if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> critical(__VA_ARGS__))


    //Client Logs
    #define OCEAN_TRACE(...)    if (::Ocean::Log::GetClientLogger() != nullptr) (::Ocean::Log::GetClientLogger() -> trace(__VA_ARGS__))
    #define OCEAN_INFO(...)     if (::Ocean::Log::GetClientLogger() != nullptr) (::Ocean::Log::GetClientLogger() -> info(__VA_ARGS__))
    #define OCEAN_DEBUG(...)    if (::Ocean::Log::GetClientLogger() != nullptr) (::Ocean::Log::GetClientLogger() -> debug(__VA_ARGS__))
    #define OCEAN_WARN(...)     if (::Ocean::Log::GetClientLogger() != nullptr) (::Ocean::Log::GetClientLogger() -> warn(__VA_ARGS__))
    #define OCEAN_ERROR(...)    if (::Ocean::Log::GetClientLogger() != nullptr) (::Ocean::Log::GetClientLogger() -> error(__VA_ARGS__))
    #define OCEAN_CRITICAL(...) if (::Ocean::Log::GetClientLogger() != nullptr) (::Ocean::Log::GetClientLogger() -> critical(__VA_ARGS__))
#else // Disable loging for release builds

    #define OCEAN_CORE_TRACE(...)     (void)0
    #define OCEAN_CORE_INFO(...)      (void)0
    #define OCEAN_CORE_DEBUG(...)     (void)0
    #define OCEAN_CORE_WARN(...)      (void)0
    #define OCEAN_CORE_ERROR(...)     (void)0
    #define OCEAN_CORE_CRITICAL(...)  (void)0

    #define OCEAN_TRACE(...)    (void)0
    #define OCEAN_INFO(...)     (void)0
    #define OCEAN_DEBUG(...)    (void)0
    #define OCEAN_WARN(...)     (void)0
    #define OCEAN_ERROR(...)    (void)0
    #define OCEAN_CRITICAL(...) (void)0
#endif

// ------------ Event System ------------------
#define BIT(x) (1 << x)

// TODO Add other macros services