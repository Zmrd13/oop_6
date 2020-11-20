cmake_minimum_required(VERSION 3.1)
project(oop_4_alt)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(oop_4_alt main.cpp clSource.h)
target_link_libraries(oop_4_alt sfml-graphics sfml-audio)
