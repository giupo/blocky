cmake_minimum_required(VERSION 2.8.9)
set(EXECUTABLE blocky)
project(${EXECUTABLE})

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(FindPackageHandleStandardArgs)
include(FindGTest)

include_directories(include)

find_package(SDL2 REQUIRED)
find_package(Chipmunk REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${CHIPMUNK_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")

add_executable(${EXECUTABLE} ${SOURCES})
target_link_libraries(${EXECUTABLE} ${SDL2_LIBRARY})
target_link_libraries(${EXECUTABLE} ${CHIPMUNK_LIBRARY})

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/config $<TARGET_FILE_DIR:${EXECUTABLE}>)
