cmake_minimum_required(VERSION 3.4)
project(example)

SET(CMAKE_PREFIX_PATH "/deployment/pybind11/build/mock_install/share/cmake/pybind11")

find_package(pybind11 REQUIRED)  # or `add_subdirectory(pybind11)`

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(example PRIVATE pybind11::embed)

set (source "${CMAKE_SOURCE_DIR}/hello.py")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/hello.py")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)