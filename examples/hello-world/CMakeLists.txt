add_executable(hello-world hello-world.cpp)
add_dependencies(hello-world
    mxg
    mxgsdl
)

target_link_libraries(hello-world
    mxg
    mxgsdl

    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
)
