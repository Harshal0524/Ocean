#pragma once

#include "Ocean/Log.h"
#include "spdlog/spdlog.h"

//Logging macros
#define OCEAN_DEFAULT_LOGGER_NAME "Oceanlogger"
#ifndef OCEAN_CONFIG_RELEASE
    #define OCEAN_TRACE(...)    if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> trace(__VA_ARGS__))
    #define OCEAN_INFO(...)     if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> info(__VA_ARGS__))
    #define OCEAN_DEBUG(...)    if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> debug(__VA_ARGS__))
    #define OCEAN_WARN(...)     if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> warn(__VA_ARGS__))
    #define OCEAN_ERROR(...)    if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> error(__VA_ARGS__))
    #define OCEAN_CRITICAL(...) if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> critical(__VA_ARGS__))
#else // Disable loging for release builds
    #define OCEAN_TRACE(...)    (void)0
    #define OCEAN_INFO(...)     (void)0
    #define OCEAN_DEBUG(...)    (void)0
    #define OCEAN_WARN(...)     (void)0
    #define OCEAN_ERROR(...)    (void)0
    #define OCEAN_CRITICAL(...) (void)0
#endif

// TODO Add other macros 