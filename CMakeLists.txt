cmake_minimum_required(VERSION 3.12)

# Det of matrices (DOM)
set(TARGET 
    dom
)
set(SOURCES
    src/main.cpp
    src/matrix.h
    src/matrix.cpp
    src/calcnonzero.h
    src/calcnonzero.cpp
)

project(${TARGET})

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

add_executable(${TARGET} ${SOURCES})

target_compile_features(${TARGET} PRIVATE cxx_std_11)