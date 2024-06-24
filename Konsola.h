//
// Created by Mateusz Szabatin on 19.06.2024.
//

#ifndef GAMEPROJECT_KONSOLA_H
#define GAMEPROJECT_KONSOLA_H
#include <SFML/Graphics.hpp>
#include <sstream>

class Konsola {
public:
    Konsola(float height, sf::Font &czcionka, sf::Vector2u windowSize);
    void wyswietl(sf::RenderWindow& window);
    void ustawSlowo(const std::string &slowo);
    void ustawPunktacje(int numb);

private:
    int numb;
    float h;
    sf::RectangleShape panel;
    sf::Font &czcionka1;
    sf::Text tekst;
    sf::Text points;
};
#endif //GAMEPROJECT_KONSOLA_H
