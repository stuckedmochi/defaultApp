cmake_minimum_required(VERSION 4.0)

project(DefaultApp)

find_package(SDL3 REQUIRED)

add_library(DefaultApp STATIC
    src/defaultApp.cpp
    src/default_create_app.cpp
)

target_include_directories(DefaultApp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(DefaultApp PUBLIC SDL3::SDL3)