file(GLOB_RECURSE ENGINE_SOURCES
    src/*.cpp
)

add_library(Ocean SHARED
    ${ENGINE_SOURCES}
)

target_include_directories(Ocean PUBLIC
    include
)