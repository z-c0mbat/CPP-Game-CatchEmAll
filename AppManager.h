//
// Created by Андрей on 21.05.2022.
//
#pragma once

#include<vector>
#include "Functions.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <fstream>

class AppManager {
private:
    ///window
    sf::RenderWindow *window;
    ///functions class
    Functions func;

    sf::Vector2i mousePos;
    sf::Vector2i mousePosLast;

    sf::Font font;

    sf::Text scoreText;
    sf::Text bonusText;
    sf::Text resultText;
    sf::Text bestScoreText;
    sf::Text time;
    std::vector<sf::Text> bonusTexts;
    std::vector<int> bonusTextTimers;

    ///timer over one second
    int timer;
    ///seconds left
    int sec;
    ///health points
    int healthPoints;
    ///spawn of enemy timer
    int enemySpawnTimer;
    ///maximum timer of enemy spawn
    int enemySpawnTimerMax;
    ///maximum amount of enemies
    int maxEnemies;
    ///if the game is paused
    bool paused;
    ///if the game is ended
    bool ended;

    std::vector<sf::Texture> images;
    sf::RectangleShape enemy;
    std::vector<sf::RectangleShape> enemies;
    std::vector<int> enemiesType;
    std::vector<float> enemiesAngleSpeed;
    sf::RectangleShape basket;

    sf::Texture pauseButtonTex;
    sf::RectangleShape pauseButton;
    sf::Texture continueButtonTex;
    sf::RectangleShape continueButton;
    sf::Texture restartButtonTex;
    sf::RectangleShape restartButton;

    sf::RectangleShape blurPannel;

    ///initializing functions
    void initVars();

    void initUI();

    void initFontsAndImg();

    void initText();

public:
    AppManager(sf::RenderWindow &win);

    ///main functions
    void spawnEnemy();

    void getPoints(int opt);

    void Pause();

    void EndGame();

    void StartOfGame();

    void WriteBestScore(int score);

    void EndGameByTimer();

    void RestartAllValues();

    void updateMousePosition();

    void updateScoreText();

    void updateBonusText();

    void updateTimer();

    void updateEnemies();

    void update();

    void renderObjects(sf::RenderTarget &win);
};
