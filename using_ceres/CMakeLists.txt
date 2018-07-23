cmake_minimum_required (VERSION 2.6)
project (using_ceres)
find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)

include_directories(
    include
    ${CERES_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
    )

add_executable(extractRT src/extractRT.cpp)
target_link_libraries(extractRT ${CERES_LIBRARIES})
