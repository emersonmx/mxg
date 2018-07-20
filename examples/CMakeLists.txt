add_executable(init_example
    init_example.cpp
)

add_dependencies(init_example
    mxgsdl
)

target_link_libraries(init_example
    mxgsdl

    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)
