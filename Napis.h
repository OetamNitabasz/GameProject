//
// Created by mateu on 22.05.2024.
//

#ifndef GAMEPROJECT_NAPIS_H
#define GAMEPROJECT_NAPIS_H
#include <SFML/Graphics.hpp>
#include "Czcionki.h"

class Napis {

public:
    Napis(const std::string napis, unsigned int rozmiar, sf::Font& czcionka,
          sf::Color kolor, float x ,float y, float predkosc);
    bool rysuj(sf::RenderWindow& window);
    Napis(const Napis& napis);
    float sprawdzSlowo(const std::string& slowo);
    float poziom();
    void ustawRozmiar(int wielkosc);
    void zapisz(std::ostream &plik);
    static Napis wczytaj(const std::string &linia, Czcionki &czcionki);

private:
    float punktacja();

    std::string lowerCase;
    sf::Text tekst;
    float speed;
    sf::Font& czcionka1;
};

#endif //GAMEPROJECT_NAPIS_H