cmake_minimum_required(VERSION 3.14)
project(processing)

set(CMAKE_PREFIX_PATH ../thirdparty/libtorch/)
find_package(Torch REQUIRED)

#add_executable(${PROJECT_NAME} src/processing.cpp)
add_library(${PROJECT_NAME} SHARED "src/processing.cpp" "include/processing.h")
target_link_libraries(${PROJECT_NAME} PUBLIC "${TORCH_LIBRARIES}")


