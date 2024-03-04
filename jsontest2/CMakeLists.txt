cmake_minimum_required(VERSION 3.27)
project(jsontest2)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE CMAKE_SOURCE_DIR)

#add_executable(jsontest2 main.cpp)

#[[include_directories(${PROJECT_SOURCE_DIR})   <------ works as well]]

set(SOURCE_FILES main.cpp )
add_executable(jsontest2 ${SOURCE_FILES})

target_include_directories(jsontest2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})