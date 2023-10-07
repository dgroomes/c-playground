# A CMakeLists.txt file describes how the build system should be configured. It helps you actually generate the build
# system (Makefile, etc).

cmake_minimum_required(VERSION 3.26)

project(CmakeWithExternalLibary VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        roaring
        GIT_REPOSITORY https://github.com/RoaringBitmap/CRoaring.git
        GIT_TAG v2.0.2
        GIT_SHALLOW TRUE)

set(ENABLE_ROARING_TESTS OFF CACHE INTERNAL "")
set(ROARING_BUILD_STATIC ON CACHE INTERNAL "")

# Make the content from "roaring" available for this project.
FetchContent_MakeAvailable(roaring)

# Add an executable target named "demo" and specify that it should be built from main.c
add_executable(demo main.c)

# Link the "roaring" library with the "demo" executable
target_link_libraries(demo PUBLIC roaring)
