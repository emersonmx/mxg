include(${PROJECT_SOURCE_DIR}/cmake/configs/libs/gtest.cmake)

# Tests
file(GLOB SRCS *.cpp)

add_executable(mxg_tests ${SRCS})

target_link_libraries(mxg_tests
    libgtest
    libgmock
    libgmock_main
    mxg
)
