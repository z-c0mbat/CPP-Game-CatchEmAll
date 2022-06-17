//
// Created by Андрей on 21.05.2022.
//

#include "AppManager.h"
#include <fstream>

/**
 * Initializing default variables
*/
void AppManager::initVars() {
    std::srand(std::time(nullptr));
    this->timer = 60;
    this->sec = 60;
    this->healthPoints = 0;
    this->enemySpawnTimerMax = 15;
    this->enemySpawnTimer = 20;
    this->maxEnemies = 15;
    this->func = Functions();
}

/**
 * Initializing user interface
*/
void AppManager::initUI() {
    this->blurPannel.setFillColor(sf::Color(220, 220, 220, 100));
    this->blurPannel.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->blurPannel.setPosition(0, 0);

    this->pauseButtonTex.loadFromFile("../res/Sprite/Pause.png");
    this->pauseButton.setTexture(&this->pauseButtonTex);
    this->pauseButton.setPosition(this->window->getSize().x - 100, 5);
    this->pauseButton.setSize(sf::Vector2f(60, 80));
    this->pauseButton.setFillColor(sf::Color(50, 50, 50, 255));

    this->continueButtonTex.loadFromFile("../res/Sprite/PlayIMG.png");
    this->continueButton.setTexture(&this->continueButtonTex);
    this->continueButton.setPosition(this->window->getSize().x / 2 - 50, this->window->getSize().y / 2 - 50);
    this->continueButton.setSize(sf::Vector2f(100, 100));
    this->continueButton.setFillColor(sf::Color(50, 50, 50, 255));

    this->restartButtonTex.loadFromFile("../res/Sprite/Reset_Sprite.png");
    this->restartButton.setTexture(&this->restartButtonTex);
    this->restartButton.setPosition(this->window->getSize().x / 2 - 50, this->window->getSize().y / 2 - 50);
    this->restartButton.setSize(sf::Vector2f(100, 100));
    this->restartButton.setFillColor(sf::Color(50, 50, 50, 255));
}

/**
 * Initializing fonts and textures
*/
void AppManager::initFontsAndImg() {
    this->font.loadFromFile("../res/Font/Raleway-Bold.ttf");
    sf::Texture a;
    a.loadFromFile("../res/Sprite/apple.png");
    this->images.push_back(a);
    a.loadFromFile("../res/Sprite/banana.png");
    this->images.push_back(a);
    a.loadFromFile("../res/Sprite/blackberry.png");
    this->images.push_back(a);
    a.loadFromFile("../res/Sprite/raspberry.png");
    this->images.push_back(a);
    a.loadFromFile("../res/Sprite/strawberry.png");
    this->images.push_back(a);
    a.loadFromFile("../res/Sprite/bomb.png");
    this->images.push_back(a);
    a.loadFromFile("../res/Sprite/basket.png");
    this->images.push_back(a);
    this->basket.setTexture(&this->images[6]);
    this->basket.setSize(sf::Vector2f(200, 200));
    this->basket.setOrigin(this->basket.getLocalBounds().width / 2, this->basket.getLocalBounds().height / 2);
}

/**
 * Initializing texts
*/
void AppManager::initText() {
    this->scoreText.setPosition(10, 5);
    this->scoreText.setFont(this->font);
    this->scoreText.setCharacterSize(40);
    this->scoreText.setFillColor(sf::Color(50, 50, 50, 255));
    this->scoreText.setString("");

    this->bonusText.setPosition(0, 0);
    this->bonusText.setFont(this->font);
    this->bonusText.setCharacterSize(40);

    this->resultText.setFont(this->font);
    this->resultText.setCharacterSize(50);
    this->resultText.setFillColor(sf::Color(50, 50, 50, 255));

    this->bestScoreText.setFont(this->font);
    this->bestScoreText.setCharacterSize(50);
    this->bestScoreText.setFillColor(sf::Color(50, 50, 50, 255));

    this->time.setFont(this->font);
    this->time.setCharacterSize(50);
    this->time.setFillColor(sf::Color(50, 50, 50, 255));
    this->time.setString("60");
    this->time.setOrigin(this->time.getGlobalBounds().width / 2, this->time.getGlobalBounds().height / 2);
    this->time.setPosition(window->getSize().x / 2, 5);
}

/**
 * Constructor
*/
AppManager::AppManager(sf::RenderWindow &win) {
    this->window = &win;
    this->initUI();
    this->initFontsAndImg();
    this->initText();
    this->initVars();
    this->StartOfGame();
}

/**
 * Called when it's time to spawn an enemy;
 * Function: spawning enemies with random size, position and rotation;
 * rnd_size: random size of enemy;
 * rnd_speed: random angle speed of enemy;
 * rnd_x: random position of enemy on X axis;
 * type: defines a texture that will be given to enemy;
*/
void AppManager::spawnEnemy() {
    //Randomize and set enemy transform parameters
    int rnd_size;
    float rnd_speed = (float) (std::rand() % 20) / 10.f;
    rnd_size = std::rand() % 80 + 100;
    int rnd_x = std::rand() % (int) (window->getSize().x - 2 * this->enemy.getLocalBounds().width - 100) +
                this->enemy.getLocalBounds().width + 100;
    this->enemy.setSize(sf::Vector2f(rnd_size, rnd_size + (60.f * ((float) rnd_size / 360.f))));
    this->enemy.setOrigin(this->enemy.getLocalBounds().width / 2, this->enemy.getLocalBounds().height / 2);
    this->enemy.setPosition(rnd_x - this->enemy.getLocalBounds().width / 2, 0);

    //Randomize enemy type and give him a texture of type
    int type = std::rand() % 6;
    this->enemy.setTexture(&this->images[type]);

    //Add enemy and his parameters to vectors
    this->enemies.push_back(this->enemy);
    this->enemiesType.push_back(type);
    this->enemiesAngleSpeed.push_back(rnd_speed);
}

/**
 * Called after best score is restored;
 * Function: display the text with score;
*/
void AppManager::WriteBestScore(int score){
    std::string bestSc;
    bestSc = "Best score was: " + std::to_string(score);

    this->bestScoreText.setString(bestSc);
    this->bestScoreText.setOrigin(this->bestScoreText.getGlobalBounds().width / 2,
                                  this->bestScoreText.getGlobalBounds().height / 2);
    this->bestScoreText.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2 + 100);
}

/**
 * Called on start of the game;
 * Function: getting last best score and displaying it before game;
*/
void AppManager::StartOfGame() {
    WriteBestScore(this->func.GetBestScore());
    this->healthPoints = 20;
    this->paused = true;
    this->ended = true;
}

/**
 * Called when pressed ESCAPE or when pressed button on screen;
 * Function: stops update processes and displaying UI;
*/
void AppManager::Pause() {
    WriteBestScore(this->func.GetBestScore());
    this->continueButton.setPosition(this->window->getSize().x / 2 - 110, this->window->getSize().y / 2 - 50);
    this->restartButton.setPosition(this->window->getSize().x / 2 + 10, this->window->getSize().y / 2 - 50);
    this->paused = true;
}

/**
 * Called when user gets 0 or negative score;
 * Function: stops the game and gives a chance to restart, displays best score;
*/
void AppManager::EndGame() {
    this->ended = true;

    this->resultText.setString("Better luck next time!");
    this->resultText.setOrigin(this->resultText.getGlobalBounds().width / 2,
                               this->resultText.getGlobalBounds().height / 2);
    this->resultText.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2 - 120);
    this->continueButton.setPosition(this->window->getSize().x / 2 - 50, this->window->getSize().y / 2 - 50);
    this->restartButton.setPosition(this->window->getSize().x / 2 - 50, this->window->getSize().y / 2 - 50);

    WriteBestScore(this->func.GetBestScore());
}

/**
 * Called when time is over;
 * Function: stops the game and gives a chance to restart, displays best score, writes new best score if it's bigger than last;
*/
void AppManager::EndGameByTimer() {
    this->ended = true;

    if (this->healthPoints > 0) {
        this->resultText.setString(std::to_string(this->healthPoints));
        this->resultText.setOrigin(this->resultText.getGlobalBounds().width / 2,
                                   this->resultText.getGlobalBounds().height / 2);
        this->resultText.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2 - 120);
        this->continueButton.setPosition(this->window->getSize().x / 2 - 50, this->window->getSize().y / 2 - 50);
        this->restartButton.setPosition(this->window->getSize().x / 2 - 50, this->window->getSize().y / 2 - 50);
        int a = this->func.GetBestScore();
        if (a < this->healthPoints) {
            std::ofstream outFile("../res/bestScore.txt");
            outFile << std::to_string(this->healthPoints) << std::endl;
            outFile.close();
        }
    } else {
        EndGame();
    }
}

/**
 * Called on restart
 * Function: restarts all values to default;
*/
void AppManager::RestartAllValues() {
    this->timer = 60;
    this->sec = 60;
    this->enemies.clear();
    this->enemiesType.clear();
    this->enemiesAngleSpeed.clear();
    this->bonusTexts.clear();
    this->bonusTextTimers.clear();
    this->enemySpawnTimer = 0;
    this->healthPoints = 20;
    this->paused = false;
    this->ended = false;
}

/**
 * Called every frame;
 * Function: gets mouse position, sets basket to mouse pos X, gets clicks on buttons;
*/
void AppManager::updateMousePosition() {
    this->mousePos = sf::Mouse::getPosition(*this->window);
    //if playing
    if (!this->paused) {
        this->basket.setPosition(mousePos.x, this->window->getSize().y - 80);
        if (this->mousePos.x < this->mousePosLast.x) {
            this->basket.setRotation(-3);
        } else if (this->mousePos.x > this->mousePosLast.x) {
            this->basket.setRotation(3);
        } else {
            this->basket.setRotation(0);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->pauseButton.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y)) {
            this->Pause();
        }
    }
    //saving last mouse position
    this->mousePosLast = this->mousePos;

    //if game ended
    if (this->ended && !this->paused) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->restartButton.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y)) {
            RestartAllValues();
        }
    } else if (this->paused && !this->ended) {    //if game paused
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->continueButton.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y)) {
            this->paused = false;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->restartButton.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y)) {
            RestartAllValues();
        }
    } else if (this->paused && this->ended) {  //if in menu
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->continueButton.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y)) {
            this->paused = false;
            this->ended = false;
        }
    }
}

/**
 * Called when user catches enemy;
 * Function: displays bonus text;
 * @param opt: 0 - user caught enemy, 1 - user caught bomb, 2 - user didn't catch enemy
*/
void AppManager::getPoints(int opt) {
    switch (opt) {
        case 0:
            this->bonusText.setString("+1");
            this->bonusText.setFillColor(sf::Color::Green);
            this->healthPoints += 1;
            break;
        case 1:
            this->bonusText.setString("-10");
            this->bonusText.setFillColor(sf::Color::Red);
            this->healthPoints -= 10;
            break;
        case 2:
            this->bonusText.setString("-3");
            this->bonusText.setFillColor(sf::Color::Red);
            this->healthPoints -= 3;
            break;
    }
    //display bonus text
    this->bonusText.setPosition(15, 60);
    this->bonusTexts.push_back(this->bonusText);
    this->bonusTextTimers.push_back(0);
    if (this->healthPoints <= 0) {    //if user lost
        this->EndGame();
    }
}

/**
 * Called every frame when in game;
 * Function: moves bonus texts;
*/
void AppManager::updateBonusText() {
    for (int i = 0; i < this->bonusTexts.size(); i++) {
        if (this->bonusTextTimers[i] < 30) {
            this->bonusTexts[i].setPosition(15, this->bonusTexts[i].getPosition().y - 1);
            this->bonusTextTimers[i] += 1;
        } else {
            this->bonusTexts.erase(this->bonusTexts.begin() + i);
            this->bonusTextTimers.erase(this->bonusTextTimers.begin() + i);
        }
    }
}

/**
 * Called every frame when in game;
 * Function: decreases the timer every 60 frames, when time is over it calls EndGameByTimer;
*/
void AppManager::updateTimer() {
    this->timer -= 1;
    if (this->timer <= 0) {
        this->sec -= 1;
        this->time.setString(std::to_string(sec));
        this->time.setOrigin(this->time.getGlobalBounds().width / 2, this->time.getGlobalBounds().height / 2);
        this->time.setPosition(window->getSize().x / 2, 5);
        this->timer = 60;
        if (this->sec == 0) {
            this->EndGameByTimer();
        }
    }
}

/**
 * Called every frame when in game;
 * Function: spawns, moves enemies, checks if user caught enemy or not;
*/
void AppManager::updateEnemies() {
    //Updating the timer for enemy spawn
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        } else
            this->enemySpawnTimer += 1.f;
    }

    //Move and check if we catch
    for (int i = 0; i < this->enemies.size(); i++) {
        this->enemies[i].move(0.f, 5.f);
        this->enemies[i].rotate(this->enemiesAngleSpeed[i]);

        if (this->enemies[i].getPosition().y > this->window->getSize().y - 80 &&
            this->enemies[i].getPosition().y < this->window->getSize().y - 50) {
            //if we catch
            if (this->enemies[i].getGlobalBounds().contains(this->mousePos.x, this->enemies[i].getPosition().y)) {
                if (this->enemiesType[i] != 5) {    //if we catch bomb
                    this->getPoints(0);
                } else {
                    this->getPoints(1);
                    std::cout << "Boom!" << "\n";
                }
                this->enemies.erase(this->enemies.begin() + i);
                this->enemiesType.erase(this->enemiesType.begin() + i);
                this->enemiesAngleSpeed.erase(this->enemiesAngleSpeed.begin() + i);
            }
        } else if (this->enemies[i].getPosition().y > this->window->getSize().y + 50) {  //if we dont catch
            if (this->enemiesType[i] != 5) {
                this->getPoints(2);
            }
            this->enemies.erase(this->enemies.begin() + i);
            this->enemiesType.erase(this->enemiesType.begin() + i);
            this->enemiesAngleSpeed.erase(this->enemiesAngleSpeed.begin() + i);
        }
    }
}

/**
 * Called every frame;
 * Function: calls other update functions;
*/
void AppManager::update() {
    this->updateMousePosition();
    if (!this->paused && !this->ended) {
        this->updateBonusText();
        this->updateScoreText();
        this->updateEnemies();
        this->updateTimer();
    }
}

/**
 * Called every frame when in game;
 * Function: updates the current score text;
*/
void AppManager::updateScoreText() {
    this->scoreText.setString(std::to_string(this->healthPoints));
}

/**
 * Called after update;
 * Function: renders all objects on screen;
 * @param win: RenderTarget for displaying objects
*/
void AppManager::renderObjects(sf::RenderTarget &win) {
    if (!this->paused && !this->ended) {
        win.draw(this->basket);
    }
    win.draw(this->pauseButton);
    win.draw(this->scoreText);
    win.draw(time);
    for (auto a: this->enemies) {
        win.draw(a);
    }
    for (auto b: this->bonusTexts) {
        win.draw(b);
    }
    if (this->paused && !this->ended) {
        win.draw(this->blurPannel);
        win.draw(this->continueButton);
        win.draw(this->restartButton);
        win.draw(this->bestScoreText);
    }
    if (this->ended && !this->paused) {
        win.draw(this->blurPannel);
        win.draw(this->restartButton);
        win.draw(this->resultText);
        win.draw(this->bestScoreText);
    }
    if (this->paused && this->ended) {
        win.draw(this->blurPannel);
        win.draw(this->continueButton);
        win.draw(this->resultText);
        win.draw(this->bestScoreText);
    }
}