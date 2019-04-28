cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

if(MSVC)
    add_compile_options(/W3 /O2 /MT)
else()
    add_compile_options(-O3) 
endif()

add_executable(test main.cpp)
find_package(OpenMP REQUIRED)
target_link_libraries(test OpenMP::OpenMP_CXX)