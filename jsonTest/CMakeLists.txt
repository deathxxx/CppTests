cmake_minimum_required(VERSION 3.27)
project(jsonTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(jsonTest main.cpp)

include(FetchContent)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(jsonTest PRIVATE nlohmann_json::nlohmann_json)