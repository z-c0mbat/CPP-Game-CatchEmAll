//
// Created by Андрей on 21.05.2022.
//
#pragma once

#include<iostream>
#include<vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class AppManager {
private:
    sf::RenderWindow *window;

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

    int timer;
    int sec;
    int healthPoints;
    int enemySpawnTimer;
    int enemySpawnTimerMax;
    int maxEnemies;
    bool paused;
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

    void initVars();

    void initUI();

    void initFontsAndImg();

    void initText();

public:
    AppManager(sf::RenderWindow &win);

    bool inTest;

    //Functions
    void spawnEnemy();

    void getPoints(int opt);

    void Pause();

    void EndGame();

    void StartOfGame();

    auto GetBestScore(bool saveNewScore);

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
