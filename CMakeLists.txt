cmake_minimum_required(VERSION 3.5)

project(cpp-learn)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(main "${SOURCES}")

add_custom_target(run 
  COMMAND main 
  DEPENDS main
)