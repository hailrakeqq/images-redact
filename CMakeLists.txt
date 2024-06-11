cmake_minimum_required(VERSION 3.10)
project(images-redact C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(CMAKE_C_STANDARD 11)

add_executable(images-redact main.c)

target_include_directories(images-redact PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_libraries(images-redact PRIVATE ${GTK3_LIBRARIES})

install(TARGETS images-redact DESTINATION bin)