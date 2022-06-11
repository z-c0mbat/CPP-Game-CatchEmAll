#include <iostream>
#include "AppManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1080,720,32),"Catch em all");
    window.setFramerateLimit(60);

    auto app = AppManager(window);

    //when in game
    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    std::cout << "Pause" << std::endl;
                    app.Pause();
                }
            }
        }
        ///UPDATE
        app.update();
        ///RENDER
        window.clear(sf::Color(220,220,220,255));
        app.renderObjects(window);
        window.display();
    }
    return 0;
}
