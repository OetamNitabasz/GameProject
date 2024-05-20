#include <iostream>
#include <SFML/Graphics.hpp>
#include "Napisy.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Monkey typer");

    sf::Texture b;
    sf::Sprite background;
    if(!b.loadFromFile("../background.jpg")) {
        std::cerr << "blad" << std::endl;
    }
    background.setTexture(b);
    Napisy napisy;
    while(window.isOpen()) {
        auto event = sf::Event();
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
       // window.draw(background);
        window.clear();
        napisy.rysuj(window);
        window.display();

    }
}