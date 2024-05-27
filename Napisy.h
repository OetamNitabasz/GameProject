//
// Created by Mateusz Szabatin on 20.05.2024.
//

#ifndef GAMEPROJECT_NAPISY_H
#define GAMEPROJECT_NAPISY_H

#include <SFML/Graphics.hpp>
#include "Napis.h"
#include <list>

sf::Font wczytajFont(const std::string& plik);

class Napisy {
public:
    void wyswietl(sf::RenderWindow& window);
    void dodaj(Napis napis);
    int zgubioneNapisy();

private:
    sf::Font czcionka1;
    std::list<Napis> napisy;
    int zgubione = 0;
};

#endif //GAMEPROJECT_NAPISY_H