cmake_minimum_required(VERSION 3.21)
project(Game_02)

set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

add_subdirectory(external/doctest)

add_executable(Game_test Test.cpp)
target_link_libraries(Game_test doctest)

add_test(NAME Test COMMAND Test --force-colors -d)
add_custom_target(cloud-test COMMAND Test --force-colors -d)

add_executable(Game main.cpp AppManager.cpp)
target_link_libraries(Game sfml-graphics sfml-audio)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
