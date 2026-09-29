cmake_minimum_required(VERSION 3.16)

project(MyProject LANGUAGES C CXX)

# Language standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Default to a Debug build if none was specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Put all built executables in build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ---- Executables ----
# add_executable(<name> <source files...>)
add_executable(adj_list "dom1/adj_list(bfs,dfs).cpp")
add_executable(edge_list "dom1/edge_list(bfs,dfs).cpp")
add_executable(adj_matrix "dom1/adj_matrix(bfs,dfs).cpp")

# Examples of adding more:
# add_executable(task1 task1.cpp)
# add_executable(task2 task2.c)
# add_executable(app src/app.cpp src/utils.cpp)