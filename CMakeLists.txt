cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)

set(EXECUTABLE blocky)
set(TEST_EXECUTABLE test_blocky)

project(${EXECUTABLE})

set(DEPS ${PROJECT_SOURCE_DIR}/deps)

macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
    else()
      set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}") 
    endif()
  else()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

use_cxx11()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(ExternalProject)
include(FindPackageHandleStandardArgs)

############ LIBS
# spdlog
ExternalProject_Add(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG "master"
  
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  
  SOURCE_DIR "${DEPS}/spdlog"
  # CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEPS}/lib/spdlog

  INSTALL_COMMAND ""
  TEST_COMMAND ""
)

set(spdlog_INCLUDE_DIRS "${DEPS}/spdlog/include")
set(spdlog_LIBRARIES "${DEPS}/lib/spdlog/lib")

include_directories(${spdlog_INCLUDE_DIRS})
# spdlog end

# config4cpp
ExternalProject_Add(
  config4cpp
  GIT_REPOSITORY "https://github.com/giupo/config4cpp.git"
  GIT_TAG "master"
  
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  CONFIGURE_COMMAND  ""
  SOURCE_DIR "${DEPS}/config4cpp"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1

  INSTALL_COMMAND ""
  TEST_COMMAND ""
)

set(config4cpp_INCLUDE_DIRS "${DEPS}/config4cpp/include")
set(config4cpp_LIBRARIES "${DEPS}/config4cpp/lib")

include_directories(${config4cpp_INCLUDE_DIRS})
# end config4cpp

############# END LIBS

include_directories(include)
# submodules

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")

add_executable(${EXECUTABLE} ${SOURCES})

set_property(TARGET ${EXECUTABLE} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${EXECUTABLE} PROPERTY CXX_STANDARD_REQUIRED ON)

add_dependencies(${EXECUTABLE} spdlog)
add_dependencies(${EXECUTABLE} config4cpp)

target_link_libraries(${EXECUTABLE} ${SDL2_LIBRARY})
target_link_libraries(${EXECUTABLE} ${SDL2_IMAGE_LIBRARY})
target_link_libraries(${EXECUTABLE} ${config4cpp_LIBRARIES}/libconfig4cpp.a)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/config $<TARGET_FILE_DIR:${EXECUTABLE}>)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${EXECUTABLE}>)

file(GLOB TEST_SOURCES "tests/*.cpp" "src/*.cpp")

# Rimuovo il main per non dichiararlo 2 volte
list(REMOVE_ITEM TEST_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

##################################
# Download and install GoogleTest

ExternalProject_Add(
  googletest
  GIT_REPOSITORY "https://github.com/google/googletest.git"
  GIT_TAG "master"
  
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  
  SOURCE_DIR "${DEPS}/googletest"
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEPS}/lib/googletest
  
  TEST_COMMAND "")

add_executable(${TEST_EXECUTABLE} ${TEST_SOURCES})
############

set_property(TARGET ${TEST_EXECUTABLE} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${TEST_EXECUTABLE} PROPERTY CXX_STANDARD_REQUIRED ON)

add_dependencies(${TEST_EXECUTABLE} googletest)
add_dependencies(${TEST_EXECUTABLE} spdlog)
  
set(googletest_INCLUDE_DIRS "${DEPS}/googletest/googletest/include")
set(googletest_LIBRARIES "${DEPS}/lib/googletest/lib")

include_directories(${googletest_INCLUDE_DIRS})

target_link_libraries(${TEST_EXECUTABLE} ${googletest_LIBRARIES}/libgtest.a)
target_link_libraries(${TEST_EXECUTABLE} ${SDL2_LIBRARY})
target_link_libraries(${TEST_EXECUTABLE} ${SDL2_IMAGE_LIBRARY})
target_link_libraries(${TEST_EXECUTABLE} ${config4cpp_LIBRARIES}/libconfig4cpp.a)

include(CTest)
enable_testing()
add_test(pippo ${TEST_EXECUTABLE})
