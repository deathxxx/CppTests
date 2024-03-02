cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CURL_INCLUDE_DIR C:/ClionProjects/curl-8.6.0_1-win64-mingw/include)
set(CURL_LIBRARY C:/ClionProjects/curl-8.6.0_1-win64-mingw/lib/libcurl.a)
#find_package(CURL REQUIRED)

add_executable(untitled main.cpp main2.cpp main3.cpp)

#target_link_libraries(untitled PRIVATE CURL::libcurl)
target_link_libraries(untitled "C:/ClionProjects/curl-8.6.0_1-win64-mingw/lib/libcurl.a")

