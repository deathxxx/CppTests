cmake_minimum_required(VERSION 3.17)
project(CurlExample)

set(CMAKE_CXX_STANDARD 14)

# Set the path to the libcurl library
#set(CURL_LIBRARY "C:/ClionProjects/curl-8.6.0_1-win64-mingw/lib/libcurl.a")
set(CURL_LIBRARY "C:/ClionProjects/curl-8.6.0_1-win64-mingw/lib/libcurl.dll.a")
set(CURL_INCLUDE_DIR "C:/ClionProjects/curl-8.6.0_1-win64-mingw/include")

# Find packages
find_package(CURL REQUIRED)

# Include directories
include_directories(${CURL_INCLUDE_DIR})

# Add executable
add_executable(CurlExample main.cpp)

# Link libraries
target_link_libraries(CurlExample ${CURL_LIBRARY})
