//
// Created by Андрей on 11.06.2022.
//

//#include "AppManager.cpp"
#include <doctest.h>
//#include <typeinfo>

TEST_CASE("Test 1") {
//    sf::RenderWindow window(sf::VideoMode(1080, 720, 32), "Catch em all");
//    window.setFramerateLimit(60);
//
//    auto app = AppManager(window);
//    int a = app.GetBestScore(false);
    REQUIRE(1+2==3);
}

extern "C" const char *__asan_default_options() {
    return "debug=1:detect_invalid_pointer_pairs=2:detect_leak=1:detect_leaks=1:leak_check_at_exit=true:color=always";
}