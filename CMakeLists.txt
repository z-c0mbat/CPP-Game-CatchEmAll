cmake_minimum_required(VERSION 3.21)
project(Game_02)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Documents/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
include_directories(C:/Documents/SFML/SFML-2.5.1/include)

add_executable(Game_02 main.cpp AppManager.cpp AppManager.h)
target_link_libraries(Game_02 sfml-graphics sfml-audio)

#add_subdirectory(external/doctest)
