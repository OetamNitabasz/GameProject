//
// Created by Mateusz Szabatin on 19.06.2024.
//

#ifndef GAMEPROJECT_KONSOLA_H
#define GAMEPROJECT_KONSOLA_H
#include <SFML/Graphics.hpp>
class Konsola {
public:
    Konsola(float height, sf::Font &czcionka, sf::Vector2u windowSize);
    void wyswietl(sf::RenderWindow& window);
    void ustawSlowo(const std::string &slowo);

private:
    float h;
    sf::RectangleShape panel;
    sf::Font &czcionka1;
    sf::Text tekst;
};
#endif //GAMEPROJECT_KONSOLA_H
