cmake_minimum_required(VERSION 3.5)

set(CMAKE_SYSTEM_NAME Windows)

set(CMAKE_C_COMPILER "/usr/bin/x86_64-w64-mingw32-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/x86_64-w64-mingw32-g++")

project(cpp-learn)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(main "${SOURCES}")

add_custom_target(run 
  COMMAND wine main 
  DEPENDS main
)