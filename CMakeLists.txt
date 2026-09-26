cmake_minimum_required(VERSION 3.16)
project(reprojection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(reprojection_app
    main.cpp
    camera.cpp
)