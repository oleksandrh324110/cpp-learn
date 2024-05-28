cmake_minimum_required(VERSION 3.5)

project(cpp-learn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_BUILD_TYPE Release)
add_subdirectory(lib/googletest)
add_subdirectory(lib/benchmark)

set(CMAKE_BUILD_TYPE DEBUG)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(main "${SOURCES}")

target_link_libraries(main gtest gtest_main benchmark::benchmark)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "test/*.cpp")

add_executable(tests "${TEST_SOURCES}")

target_link_libraries(tests gtest gtest_main)