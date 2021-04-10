cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(LibtorchDetection)

set(CMAKE_PREFIX_PATH ./thirdparty/libtorch/)
find_package(Torch REQUIRED)

include_directories(./include/)
add_executable(LibtorchDetection ./src/detection.cpp ./include/detection.h)
target_link_libraries(LibtorchDetection "${TORCH_LIBRARIES}")