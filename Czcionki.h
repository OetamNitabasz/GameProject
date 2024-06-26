//
// Created by Mateusz Szabatin on 26.06.2024.
//

#ifndef GAMEPROJECT_CZCIONKI_H
#define GAMEPROJECT_CZCIONKI_H
#include <SFML/Graphics.hpp>
#include <random>


class Czcionki {
public:
    Czcionki();
    sf::Font &dajPodstawowy();
    sf::Font &dajLosowy(std::mt19937 &rng);
    sf::Font &daj(const std::string &familiy);
private:

    void wczytajFont(const std::string &plik);
    std::vector<sf::Font> fonts;
};

#endif //GAMEPROJECT_CZCIONKI_H
