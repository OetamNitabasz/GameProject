#include <iostream>
#include <SFML/Graphics.hpp>
#include "Napisy.h"
#include "Konsola.h"

int main() {
        sf::Font czcionka = wczytajFont("../fonts/Roboto-Bold.ttf");
        sf::RenderWindow window(sf::VideoMode(800, 600), "Monkey typer",
                                sf::Style::Titlebar | sf::Style::Close);
        Napisy napisy(czcionka, sf::Vector2u(800, 550));
        Konsola konsola(50, czcionka, window.getSize());
        std::string wprowadzanyNapis;
        sf::Texture b;
        sf::Sprite background;
        if (!b.loadFromFile("../background.jpg")) {
            std::cerr << "blad" << std::endl;
        }
        background.setTexture(b);

        while (window.isOpen()) {
            auto event = sf::Event();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
               else if(event.type == sf::Event::TextEntered) {
                    if(event.text.unicode > 32 && event.text.unicode <= 126) {
                        wprowadzanyNapis += (char) event.text.unicode;
                        if(napisy.sprawdz(wprowadzanyNapis)) {
                            wprowadzanyNapis.clear();
                        }
                        konsola.ustawSlowo(wprowadzanyNapis);
                        konsola.ustawPunktacje(napisy.punktacja());
                    }
                } else if(event.type == sf::Event::KeyPressed) {
                   if(event.key.code == sf::Keyboard::BackSpace) {
                       if(!wprowadzanyNapis.empty()) {
                           wprowadzanyNapis.pop_back();
                           konsola.ustawSlowo(wprowadzanyNapis);
                       }
                   } else if(event.key.code == sf::Keyboard::Escape) {
                       wprowadzanyNapis.clear();
                       konsola.ustawSlowo(wprowadzanyNapis);
                   }
               }
            }
            // window.draw(background);
            window.setFramerateLimit(100);
            window.clear();
            konsola.wyswietl(window);
            napisy.wyswietl(window);
            if(napisy.zgubioneNapisy() >= 100) {
                window.close(); //tymaczasowo
                //wyswietlic game over + zrestartowac gre
            }
            window.display();

        }
    std::cout << "Ile zostalo zgubionych napisow: " + std::to_string(napisy.zgubioneNapisy()) << std::endl;
}