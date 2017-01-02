cmake_minimum_required(VERSION 2.8.9)
set(EXECUTABLE blocky)
project(${EXECUTABLE})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include_directories(include)
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")

add_executable(${EXECUTABLE} ${SOURCES})
target_link_libraries(${EXECUTABLE} ${SDL2_LIBRARY})
