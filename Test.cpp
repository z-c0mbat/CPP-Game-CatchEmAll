//
// Created by Андрей on 11.06.2022.
//

#include "Functions.h"
#include <doctest.h>

TEST_CASE ("Test 1") {
    Functions a = Functions();
    int b = a.GetBestScore();
            REQUIRE(typeid(b).name() == typeid(1).name());
            REQUIRE(b >= 0);
}

TEST_CASE ("Test 2") {
    Functions a = Functions();
    auto[v1, v2, v3, v4] = a.GenerateRndValues(500, 50);
            REQUIRE(typeid(v1).name() == typeid(1.f).name());
            REQUIRE(typeid(v2).name() == typeid(1).name());
            REQUIRE(typeid(v3).name() == typeid(1).name());
            REQUIRE(typeid(v4).name() == typeid(1).name());
    auto[v5, v6, v7, v8] = a.GenerateRndValues(1000, 200);
            REQUIRE(typeid(v5).name() == typeid(1.f).name());
            REQUIRE(typeid(v6).name() == typeid(1).name());
            REQUIRE(typeid(v7).name() == typeid(1).name());
            REQUIRE(typeid(v8).name() == typeid(1).name());
}

TEST_CASE ("Test 3") {
    Functions a = Functions();
    int b = a.getPts(0);
            REQUIRE(typeid(b).name() == typeid(1).name());
            REQUIRE(b > 0);
    b = a.getPts(1);
            REQUIRE(typeid(b).name() == typeid(1).name());
            REQUIRE(b < 0);
    b = a.getPts(2);
            REQUIRE(typeid(b).name() == typeid(1).name());
            REQUIRE(b < 0);
}

extern "C" const char *__asan_default_options() {
    return "debug=1:detect_invalid_pointer_pairs=2:detect_leak=1:detect_leaks=1:leak_check_at_exit=true:color=always";
}