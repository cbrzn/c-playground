cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp)

add_library(libpolywrap_ffi_swift_client SHARED IMPORTED)
set_property(TARGET libpolywrap_ffi_swift_client PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpolywrap_ffi_swift_client.so)
target_link_libraries(untitled libpolywrap_ffi_swift_client)
