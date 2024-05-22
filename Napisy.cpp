//
// Created by Mateusz Szabatin on 20.05.2024.
//
#include "Napisy.h"
#include "Napis.h"
#include <string>
#include <iostream>


/*
sf::Text utworzNapis(const std::string& napis, unsigned int rozmiar, const sf::Font& czcionka, sf::Text::Style styl,
                     sf::Color kolor) {
    sf::Text tekst(napis, czcionka, rozmiar);
    tekst.setStyle(styl);
    tekst.setFillColor(kolor);
    tekst.setPosition(0,0);
    return tekst;
}
*/


void Napisy::rysuj(sf::RenderWindow &window) {
    for(Napis& n : napisy) {
        n.rysuj(window);
    }
}

void Napisy::dodaj(Napis napis) {
    napisy.push_back(napis);
}

sf::Font wczytajFont(const std::string& plik) {
    sf::Font font;
    if(!font.loadFromFile(plik)) {
        std::cerr << "blad wczytywania czcionki" << std::endl;
        //todo zastosowac wyjatki/przerwac program
    }
    return font;
}