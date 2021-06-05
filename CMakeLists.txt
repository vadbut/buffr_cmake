# CMakeList.txt : CMake project for buffr_cmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("buffr")

set(SOURCES
    src/main.cpp
)

# Add source to this project's executable.
add_executable(hello_headers ${SOURCES})

target_include_directories(hello_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
