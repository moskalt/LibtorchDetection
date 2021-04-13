cmake_minimum_required(VERSION 3.14)
# set project name from current directory
project(v4l2lib)

set (CMAKE_CXX_STANDARD 11)

# define executable to build
include_directories("inc")
aux_source_directory(src SRC_FILES)
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

