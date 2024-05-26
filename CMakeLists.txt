cmake_minimum_required(VERSION "3.22.1")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME shl)
set(PROJECT_VERSION 0.0.1)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/shl")
target_sources(${PROJECT_NAME} PRIVATE ${SRC_FILES})
message("Included shl library")