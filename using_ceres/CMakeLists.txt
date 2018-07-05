cmake_minimum_required(VERSION 2.8)

project(hello_world)

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

# helloworld
add_executable(helloworld hello_world.cpp)
target_link_libraries(helloworld ${CERES_LIBRARIES})
