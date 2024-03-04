cmake_minimum_required(VERSION 3.27)
project(M4aID3EditV2)

set(CMAKE_CXX_STANDARD 17)

add_executable(M4aID3EditV2 main.cpp)

# install with vcpkg
#find_package(taglib CONFIG REQUIRED)
#target_link_libraries(M4aID3EditV2 PRIVATE TagLib::tag TagLib::tag_c TagLib::TagLib)

# install with brew
include_directories(/usr/local/Cellar/taglib/1.13.1/include)
target_link_libraries(M4aID3EditV2 tag)