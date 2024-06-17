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
    napisy.remove_if([](Napis& napis)
    {
        auto z = napis.zaEkranem();
        return z;});
}

bool Napisy::sprawdz(std::string slowo) {
    /*for(const Napis& n : napisy) {
        if(n.sprawdzSlowo(slowo)) {
            napisy.remove(n);
        }
    }*/
    /*napisy.remove_if([&] (Napis& napis) {
        return napis.sprawdzSlowo(slowo);
    });*/
    for(auto itr = napisy.begin(); itr != napisy.end();) {
        //if(itr->sprawdzSlowo(slowo)) {
        if(true) {
            itr = napisy.erase(itr);
        } else {
            ++itr;
        }
    }
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