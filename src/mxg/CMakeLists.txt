add_library(mxg
    Size.cpp
    Vector2.cpp
)

if (BACKEND_TYPE STREQUAL "sdl2")
    add_subdirectory(sdl2)
endif()
