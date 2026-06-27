#pragma once

#include "Ocean/Log.h"
#include "spdlog/spdlog.h"

//Logging macros
#define OCEAN_DEFAULT_ENGINE_LOGGER_NAME "OceanEnginelogger"
#define OCEAN_DEFAULT_CLIENT_LOGGER_NAME "OceanClientlogger"

#ifndef OCEAN_CONFIG_RELEASE

    //Engine Logs
    #define OCEAN_CORE_TRACE(...)     if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> trace(__VA_ARGS__))
    #define OCEAN_CORE_INFO(...)      if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> info(__VA__ARGS__))
    #define OCEAN_CORE_DEBUG(...)     if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> debug(__VA__ARGS__))
    #define OCEAN_CORE_WARN(...)      if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> warn(__VA__ARGS__))
    #define OCEAN_CORE_ERROR(...)     if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> error(__VA__ARGS__))
    #define OCEAN_CORE_CRITICAL(...)  if(::Ocean::Log::GetEngineLogger() != nullptr) (::Ocean::Log::GetEngineLogger() -> critical(__VA__ARGS__))


    //Client Logs
    #define OCEAN_TRACE(...)    if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> trace(__VA_ARGS__))
    #define OCEAN_INFO(...)     if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> info(__VA_ARGS__))
    #define OCEAN_DEBUG(...)    if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> debug(__VA_ARGS__))
    #define OCEAN_WARN(...)     if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> warn(__VA_ARGS__))
    #define OCEAN_ERROR(...)    if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> error(__VA_ARGS__))
    #define OCEAN_CRITICAL(...) if (::Ocean::Log::GetLogger() != nullptr) (::Ocean::Log::GetLogger() -> critical(__VA_ARGS__))
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

// TODO Add other macros services