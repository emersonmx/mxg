# Targets
add_library(${PROJECT_NAME}
    mxg/application/Application.cpp
    mxg/application/StateApplication.cpp
)

# Install
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
    DESTINATION include FILES_MATCHING PATTERN "*.hpp")
