cmake_minimum_required(VERSION 3.24)
project(c_playground)

set(CMAKE_CXX_STANDARD 17)

add_executable(c_playground main.cpp)

add_library(libpolywrap_ffi_c SHARED IMPORTED)
set_property(TARGET libpolywrap_ffi_c PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpolywrap_ffi_c.so)
target_link_libraries(c_playground libpolywrap_ffi_c)
