cmake_minimum_required(VERSION 3.21)
project(Game_02)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Documents/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
include_directories(C:/Documents/SFML/SFML-2.5.1/include)

#enable_testing()
add_subdirectory(external/doctest)

#add_library(default INTERFACE)
#target_compile_features(default INTERFACE cxx_std_20)
#
#include(cmake/CompilerWarnings.cmake)
#set_project_warnings(default)

add_executable(Game_test Test.cpp)
target_link_libraries(Game_test doctest)

add_test(NAME Test COMMAND Test --force-colors -d)
add_custom_target(cloud-test COMMAND Test --force-colors -d)

add_executable(Game_02 main.cpp AppManager.cpp AppManager.h)
target_link_libraries(Game_02 sfml-graphics sfml-audio)

#add_subdirectory(external/doctest)
