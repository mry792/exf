cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
project(package-test LANGUAGES CXX)

if (EXISTS conan_paths.cmake)
    include(conan_paths)
endif ()

find_package(extended-freestanding REQUIRED CONFIG)

add_executable(test test.cpp)
target_link_libraries(test extended-freestanding::std)
