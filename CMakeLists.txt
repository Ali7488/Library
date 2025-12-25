cmake_minimum_required(VERSION 3.16)
project(Library LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Checking: ${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SRC_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

message(STATUS "SRC_FILES = ${SRC_FILES}")

add_executable(library ${SRC_FILES})

target_include_directories(library PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/Include)
