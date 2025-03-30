cmake_minimum_required(VERSION 3.10.0)
project(iridescence)

IF (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    set(VCPKG_ROOT "D:/vcpkg" CACHE PATH "Path to vcpkg root directory")
    set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "vcpkg target triplet")
    set(VCPKG_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/include)
    set(VCPKG_LIB_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/lib)
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DNOMINMAX)
elseif(APPLE)
    set(VCPKG_ROOT "~/vcpkg" CACHE PATH "Path to vcpkg root directory")
    set(VCPKG_TARGET_TRIPLET "arm64-osx" CACHE STRING "vcpkg target triplet")
    set(VCPKG_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/arm64-osx/include)
    set(VCPKG_LIB_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/arm64-osx/lib)
elseif(UNIX)
    set(VCPKG_ROOT "~/vcpkg" CACHE PATH "Path to vcpkg root directory")
    set(VCPKG_TARGET_TRIPLET "x64-linux" CACHE STRING "vcpkg target triplet")
    set(VCPKG_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux/include)
    set(VCPKG_LIB_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux/lib)
endif()

include(${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

include_directories(${VCPKG_INCLUDE_DIRS})

include_directories(source/include)

add_subdirectory(source)
add_subdirectory(example)

