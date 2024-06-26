//
// Created by Mateusz Szabatin on 19.06.2024.
//

#ifndef GAMEPROJECT_KONSOLA_H
#define GAMEPROJECT_KONSOLA_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Napisy.h"

class Konsola {
public:
    Konsola(float height, sf::Font &czcionka, sf::Vector2u windowSize);
    void wyswietl(sf::RenderWindow& window);
    void ustawSlowo(const std::string &slowo);
    void ustawPunktacje(float numb);
    void ustawPredkosc(float szybkosc);
    void ustawWielkosc(WielkoscNapisu rozmiar);

private:
    float h;
    sf::RectangleShape panel;
    sf::Font &czcionka1;
    sf::Text tekst;
    sf::Text points;
    sf::Text wielkosc;
    sf::Text predkosc;
};
#endif //GAMEPROJECT_KONSOLA_H
