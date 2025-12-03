cmake_minimum_required(VERSION 3.23)

project(TestProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Your executable + sources ---

add_executable(main
    main.cpp
)

