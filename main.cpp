#include <iostream>
#include <SFML/Graphics.hpp>
#include "Napisy.h"

int main() {
    Napisy napisy;
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Monkey typer");
        std::string litery;
        sf::Texture b;
        sf::Sprite background;
        if (!b.loadFromFile("../background.jpg")) {
            std::cerr << "blad" << std::endl;
        }
        background.setTexture(b);

        sf::Font czcionka = wczytajFont("../fonts/Roboto-Bold.ttf");
        napisy.dodaj(Napis("PJATK", 24, czcionka,
                           sf::Text::Bold, sf::Color::Cyan, 0, 1));
        napisy.dodaj(Napis("POPO", 24, czcionka,
                           sf::Text::Bold, sf::Color::Red, 30, 2));
        while (window.isOpen()) {
            auto event = sf::Event();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
               else if(event.type == sf::Event::TextEntered){
                    if(event.text.unicode > 32 && event.text.unicode <= 126) {
                        litery += (char) event.text.unicode;
                        std::cout << litery << std::endl;
                        napisy.sprawdz(litery);
                    }
                }
            }
            // window.draw(background);
            window.setFramerateLimit(100);
            window.clear();
            napisy.wyswietl(window);
            window.display();

        }
    }
    std::cout << "Ile zostalo zgubionych napisow: " + std::to_string(napisy.zgubioneNapisy()) << std::endl;
}