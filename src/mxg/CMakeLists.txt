add_library(mxg
    Clock.cpp
    ClockImpl.cpp
    Size.cpp
    Time.cpp
    Vector2.cpp
)

if (BACKEND_TYPE STREQUAL "sdl2")
    add_subdirectory(sdl2)
endif()
