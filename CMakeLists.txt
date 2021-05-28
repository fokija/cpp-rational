cmake_minimum_required(VERSION 3.5)
project(ex4)

set (CMAKE_CXX_STANDARD 11)

include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE EX4_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(ex4_src ${EX4_SRC})
target_include_directories(ex4_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(ex4 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(ex4 ex4_src)

file(GLOB_RECURSE EX4_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${EX4_TEST_SRC})
target_link_libraries(tests ex4_src)
target_link_libraries(tests ${CONAN_LIBS})
