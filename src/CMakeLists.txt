include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_library(${PROJECT_NAME}
    mxg/Application.cpp
    mxg/Game.cpp
)

# Install settings
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    DESTINATION include FILES_MATCHING PATTERN "*.hpp")
