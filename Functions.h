//
// Created by Андрей on 17.06.2022.
//
#include<iostream>
#include <fstream>

class Functions {
public:
    Functions() {};

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

/**
 * Called before spawning an enemy
 * Function: returning random values with restrictions;
 * @param: windowX - window width; enemyWidth - size of enemy on x axis;
 * @return: v1 - speed; v2 - size; v3 - x coord; v4 - type;
*/
    auto GenerateRndValues(int windowX, int enemyWidth) {
        struct res {
            float v1;
            int v2;
            int v3;
            int v4;
        };
        float rnd_speed = (float) (std::rand() % 20) / 10.f;
        int rnd_size = std::rand() % 80 + 100;
        int rnd_x = std::rand() % (int) (windowX - 2 * enemyWidth - 100) + enemyWidth + 100;
        int type = std::rand() % 6;
        return res{rnd_speed, rnd_size, rnd_x, type};
    };

/**
 * Called before spawning an enemy
 * Function: returning random values with restrictions;
 * @return: v1 - speed; v2 - size; v3 - x coord; v4 - type;
*/
    auto getPts(int opt) {
        int res;
        switch (opt) {
            case 0:
                res = 1;
                break;
            case 1:
                res = -10;
                break;
            case 2:
                res = -3;
                break;
        }
        return res;
    };
};
