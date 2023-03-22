cmake_minimum_required(VERSION 3.12)

# Det of matrices (DOM)
set(TARGET 
    dom
)
set(SOURCES
    src/main.cpp
    src/matrix.cpp
    src/matrix.h
)

project(${TARGET})

set(CMAKE_BUILD_TYPE Debug)

add_executable(${TARGET} ${SOURCES})

target_compile_features(${TARGET} PRIVATE cxx_std_20)