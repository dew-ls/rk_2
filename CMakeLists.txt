cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(design)

add_executable(design src/house_and_theme.cpp)

install(TARGETS design DESTINATION bin)

if(BUILD_TESTS)
    enable_testing()
    add_executable(test tests/test.cpp)
    add_test(NAME test COMMAND test)
endif()

set(DESIGN_VERSION 0.1)
include CPackConfig.cmake
