cmake_minimum_required(VERSION 3.20)

project(Ocean)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.16.0
)

FetchContent_MakeAvailable(spdlog)

add_subdirectory(Engine)
add_subdirectory(Sandbox)
