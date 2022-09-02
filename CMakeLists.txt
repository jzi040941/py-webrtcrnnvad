cmake_minimum_required(VERSION 3.4...3.18)
project(py_webrtcrnnvad)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("using Clang")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")
    # using GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    message("using Intel c++")
    # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("using MSVC")
    # using Visual Studio C++
endif()


include_directories(src)
add_subdirectory(src)

add_subdirectory(pybind11)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true src/*.h src/*.cpp)

set(SOURCES ${SOURCES})
pybind11_add_module(_py_webrtcrnnvad ${SOURCES})

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(_py_webrtcrnnvad
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
