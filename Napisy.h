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
    Napisy(sf::Font &czcionka, sf::Vector2u size);
    void wyswietl(sf::RenderWindow& window);
    int zgubioneNapisy();
    bool sprawdz(const std::string &slowo);


private:
    void wczytaj(std::string plik);
    void dodaj(Napis napis);

    std::vector<std::string> slowa;
    sf::Font &czcionka1;
    std::list<Napis> napisy;
    int zgubione = 0;
};

#endif //GAMEPROJECT_NAPISY_H