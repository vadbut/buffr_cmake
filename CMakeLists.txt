# CMakeList.txt : CMake project for buffr_cmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("buffr")

add_subdirectory("external/glfw")
add_subdirectory("external/SFML")


set(SOURCES
    src/main.cpp
)

# Add source to this project's executable.
add_executable(buffr WIN32 ${SOURCES})

find_package(OpenGL REQUIRED)

target_include_directories(buffr PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(buffr PRIVATE ${PROJECT_SOURCE_DIR}/external/glfw/include)
target_include_directories(buffr PRIVATE ${PROJECT_SOURCE_DIR}/external/SFML/include)

target_link_libraries(buffr
    glfw
    sfml-main
    opengl32
)