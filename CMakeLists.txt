cmake_minimum_required(VERSION 2.8.9)
set(EXECUTABLE blocky)
project(${EXECUTABLE})

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(FindPackageHandleStandardArgs)

# https://cmake.org/cmake/help/v3.0/module/FindGTest.html
#
# GTEST_FOUND - Found the Google Testing framework
# GTEST_INCLUDE_DIRS - Include directories

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

enable_testing()		 
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_blocky tests/test_blocky.cpp)
target_link_libraries(test_blocky ${GTEST_BOTH_LIBRARIES})
add_test(AllTestsInBlocky test_blocky)
