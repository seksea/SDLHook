cmake_minimum_required(VERSION 3.11.0)
project(SDLHook)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS_DEBUG "-Wall -ggdb -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=c++20")
set(CMAKE_C_FLAGS_RELEASE "-Wall -O3 -march=core2 -mtune=native -s -fvisibility=hidden -flto -fwhole-program")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} --no-gnu-unique -fno-rtti -std=c++20")

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/src/menu/imgui/GL/gl3w.c")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(SDLHook SHARED ${SOURCES})
target_link_libraries(SDLHook SDL2 GL)
