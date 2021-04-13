cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(main)

#set(CMAKE_PREFIX_PATH ../thirdparty/libtorch/)
#find_package(Torch REQUIRED)

add_executable(${PROJECT_NAME} detection.cpp)
include_directories(../v4l2lib)
target_link_libraries(${PROJECT_NAME} PUBLIC v4l2lib)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/v4l2lib")