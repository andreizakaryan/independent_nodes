cmake_minimum_required(VERSION 3.19)

set(PROJECT_UNIT_TESTS_NAME ${PROJECT_NAME}_unit_tests)


find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

file(GLOB UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)


include_directories(${Boost_INCLUDE_DIRS})

add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} ${Boost_LIBRARIES})

enable_testing()
add_test(GraphTests ${PROJECT_UNIT_TESTS_NAME})
