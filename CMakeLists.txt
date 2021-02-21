cmake_minimum_required(VERSION 3.19)

project(dag_independent_nodes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB_RECURSE INC_FILES include/*)
file(GLOB_RECURSE SRC_FILES src/*)

find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

add_subdirectory(test)

include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main/main.cpp ${INC_FILES} ${SRC_FILES})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
