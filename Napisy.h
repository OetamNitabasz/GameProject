//
// Created by Mateusz Szabatin on 20.05.2024.
//

#ifndef GAMEPROJECT_NAPISY_H
#define GAMEPROJECT_NAPISY_H

#endif //GAMEPROJECT_NAPISY_H

#include <SFML/Graphics.hpp>

class Napisy {
public:
   Napisy();
   void rysuj(sf::RenderWindow& window);

private:
    sf::Font czcionka1;
    float pozycjaX = 0;

};
