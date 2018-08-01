add_executable(basic_example
    basic_example.cpp
)

add_dependencies(basic_example
    mxg
    mxgsdl
)

target_link_libraries(basic_example
    mxg
    mxgsdl

    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)
