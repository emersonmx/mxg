# Targets
add_library(${PROJECT_NAME}
    mxg/Application.cpp
    mxg/Game.cpp

    mxg/graphics/Color.cpp
)

# Install
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    DESTINATION include FILES_MATCHING PATTERN "*.hpp")
