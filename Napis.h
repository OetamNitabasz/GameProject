//
// Created by mateu on 22.05.2024.
//

#ifndef GAMEPROJECT_NAPIS_H
#define GAMEPROJECT_NAPIS_H

#include <SFML/Graphics.hpp>
#include "Konsola.h"

class Napis {

public:
    Napis(const std::string napis, unsigned int rozmiar, sf::Font& czcionka, sf::Text::Style styl,
          sf::Color kolor, float y, float predkosc);
    bool rysuj(sf::RenderWindow& window);
    Napis(const Napis& napis);
    int sprawdzSlowo(const std::string& slowo);
    float poziom();


private:
    int punktacja();

    std::string lowerCase;
    sf::Text tekst;
    float speed;
    sf::Font& czcionka1;
};

#endif //GAMEPROJECT_NAPIS_H