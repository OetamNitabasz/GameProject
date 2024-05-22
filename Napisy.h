//
// Created by Mateusz Szabatin on 20.05.2024.
//

#ifndef GAMEPROJECT_NAPISY_H
#define GAMEPROJECT_NAPISY_H

#include <SFML/Graphics.hpp>
#include "Napis.h"

sf::Font wczytajFont(const std::string& plik);

class Napisy {
public:
    void rysuj(sf::RenderWindow& window);
    void dodaj(Napis napis);

private:
    sf::Font czcionka1;
    std::vector<Napis> napisy;
};

#endif //GAMEPROJECT_NAPISY_H


