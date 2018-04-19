# Targets
add_library(mxg
    mxg/Size.cpp
    mxg/Time.cpp
    mxg/Transform.cpp
    mxg/Vector2.cpp
)
add_library(mxgsdl
    mxg/sdl/Renderer.cpp
    mxg/sdl/Texture.cpp
    mxg/sdl/TextureLoader.cpp
    mxg/sdl/Window.cpp
)
