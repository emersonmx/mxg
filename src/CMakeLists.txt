# Setup
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Config.hpp.in"
    "${PROJECT_BINARY_DIR}/Config.hpp"
)

# Targets
add_library(${PROJECT_NAME}
    mxg/Application.cpp
    mxg/Game.cpp
)

# Install
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    DESTINATION include FILES_MATCHING PATTERN "*.hpp")
