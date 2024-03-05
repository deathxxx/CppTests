cmake_minimum_required(VERSION 3.27)
project(M4aId3Edit)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE CMAKE_SOURCE_DIR)

#add_executable(M4aId3Edit main.cpp)
set(SOURCE_FILES main.cpp )
add_executable(M4aId3Edit ${SOURCE_FILES})

target_include_directories(M4aId3Edit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# trying include from other

#find_package(ZLIB REQUIRED)
#
#find_package(taglib CONFIG REQUIRED)
#include_directories(/usr/local/Cellar/taglib/1.13.1/include)
#target_link_libraries(M4aId3Edit tag)
#target_link_libraries(M4aID3EditV2 PRIVATE
#        TagLib::tag
#        #        TagLib::tag_c
#        TagLib::TagLib
#)



# anoter try 5.3.24
## Linking Directories
#link_directories(${CMAKE_SOURCE_DIR}/lib)
#
## Linking the static library
#target_link_libraries(M4aId3Edit tag)


# another try 2
set(TAGLIB_LIBRARY "/Users/dex/CLionProjects/CppTests/M4aId3Edit/lib/cmake-build-debug/libtag.a")
set(TAGLIB_INCLUDE_DIR /Users/dex/CLionProjects/CppTests/M4aId3Edit/lib)
find_package(TAGLIB REQUIRED)
include_directories(${TAGLIB_INCLUDE_DIR})
#add_library(M4aId3Edit source_files)