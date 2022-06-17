//
// Created by Андрей on 11.06.2022.
//

//#include "AppManager.h"
#include "doctest.h"
#include "iostream"

TEST_CASE("Test 1") {
    std::cout<<"Test 1"<<std::endl;
    int a = 0;
    CAPTURE(a);
    CHECK(a == 0);
    REQUIRE(a == 0);
}