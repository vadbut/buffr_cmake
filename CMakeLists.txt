# CMakeList.txt : CMake project for buffr_cmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("buffr")

# Add SFML and use it statically.
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory("external/SFML")

set(SOURCES
    src/main.cpp
)

# Add source to this project's executable.
add_executable(buffr WIN32 ${SOURCES})

find_package(OpenGL REQUIRED)

target_include_directories(buffr PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(buffr PRIVATE ${PROJECT_SOURCE_DIR}/external/SFML/include)

target_link_libraries(buffr
    dwmapi 
    sfml-main
    sfml-window
    sfml-graphics
)