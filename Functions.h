//
// Created by Андрей on 17.06.2022.
//
#include<iostream>
#include <fstream>

class Functions {
public:
    Functions(){};

/**
 * Called before we show best score to user;
 * Function: getting last best score and displaying it;
*/
    auto GetBestScore() {
        std::ifstream inFile("../res/bestScore.txt");
        int best;
        while (inFile >> best) {
            std::cout << best << std::endl;
        }
        inFile.close();
        return best;
    };
};
