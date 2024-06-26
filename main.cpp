#include <iostream>
#include <SFML/Graphics.hpp>
#include "Napisy.h"
#include "Konsola.h"
#include "Czcionki.h"

int main() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Monkey typer",
                                sf::Style::Titlebar | sf::Style::Close);
        Czcionki czcionki;
        Napisy napisy(czcionki);
        Konsola konsola(50, czcionki.dajPodstawowy(), window.getSize());
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
                    }
                } else if(event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::BackSpace) {
                        if (!wprowadzanyNapis.empty()) {
                            wprowadzanyNapis.pop_back();
                            konsola.ustawSlowo(wprowadzanyNapis);
                        }
                    } else if (event.key.code == sf::Keyboard::Escape) {
                        wprowadzanyNapis.clear();
                        konsola.ustawSlowo(wprowadzanyNapis);
                    } else if(event.key.code == sf::Keyboard::Num1 && event.key.control) {
                        napisy.ustawWielkosc(Male);
                    } else if(event.key.code == sf::Keyboard::Num2 && event.key.control) {
                        napisy.ustawWielkosc(Srednie);
                    } else if(event.key.code == sf::Keyboard::Num3 && event.key.control) {
                        napisy.ustawWielkosc(Duze);
                    } else if(event.key.code == sf::Keyboard::Num9 && event.key.control) {
                        napisy.przyspiesz();
                    } else if(event.key.code == sf::Keyboard::Num0 && event.key.control) {
                        napisy.zwolnij();
                    } else if(event.key.code == sf::Keyboard::S && event.key.control) {
                        napisy.zapisz();
                    } else if(event.key.code == sf::Keyboard::L && event.key.control) {
                        napisy.wczytaj();
                    }
                }
            }
            window.setFramerateLimit(100);
            window.clear();
            window.draw(background);
            konsola.ustawPredkosc(napisy.predkosc());
            konsola.ustawPunktacje(napisy.punktacja());
            konsola.ustawWielkosc(napisy.wielkoscNapisow());
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