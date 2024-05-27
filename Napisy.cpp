//
// Created by Mateusz Szabatin on 20.05.2024.
//
#include "Napisy.h"
#include "Napis.h"
#include <string>
#include <iostream>


void Napisy::wyswietl(sf::RenderWindow &window) {
    //w ramach jednej petli trzeba kasowac elementy od razu bez remove_if
    for(Napis& n : napisy) {
        if(!n.rysuj(window)) {
            zgubione++;
        }
    }
    napisy.remove_if([](auto napis)
    {
        auto z = napis.zaEkranem();
        return z;});
}

int Napisy::zgubioneNapisy() {
    return zgubione;
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