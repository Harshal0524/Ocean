file(GLOB_RECURSE ENGINE_SOURCES
    src/*.cpp
)

add_library(Ocean SHARED
    ${ENGINE_SOURCES}
    src/Events/Event.cpp
)

target_include_directories(Ocean PUBLIC
    include
)

target_link_libraries(Ocean PUBLIC
    spdlog::spdlog_header_only
)