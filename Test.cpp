//
// Created by Андрей on 11.06.2022.
//

#include "Functions.h"
#include <doctest.h>

TEST_CASE("Test 1") {
    Functions a = Functions();
    int b = a.GetBestScore();
    REQUIRE(typeid(b).name() == typeid(1).name());
}

TEST_CASE("Test 2") {
    Functions a = Functions();
    int b = a.GetBestScore();
            REQUIRE(typeid(b).name() == typeid(1).name());
}

extern "C" const char *__asan_default_options() {
    return "debug=1:detect_invalid_pointer_pairs=2:detect_leak=1:detect_leaks=1:leak_check_at_exit=true:color=always";
}