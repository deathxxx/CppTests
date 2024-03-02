cmake_minimum_required(VERSION 3.10)
project(curl_test_app)

set(CMAKE_CXX_STANDARD 11)

# Set the path to the libcurl library
set(CURL_LIBRARY "C:/ClionProjects/curl-8.6.0_1-win64-mingw/lib/libcurl.a")
set(CURL_INCLUDE_DIR "C:/ClionProjects/curl-8.6.0_1-win64-mingw/include")

# Find cURL package
find_package(CURL REQUIRED)

# Include cURL headers
include_directories(${CURL_INCLUDE_DIRS})

# Define your executable and sources
add_executable(${PROJECT_NAME} main.cpp)

# Link cURL libraries with your executable
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})
