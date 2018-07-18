cmake_minimum_required(VERSION 2.8)
project(using_ceres)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_executable(extractRT src/extractRT.cpp)
target_link_libraries(extractRT ${CERES_LIBRARIES})
