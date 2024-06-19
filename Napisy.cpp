//
// Created by Mateusz Szabatin on 20.05.2024.
//
#include "Napisy.h"
#include "Napis.h"
#include <string>
#include <iostream>
#include <fstream>
#include <random>


Napisy::Napisy(sf::Font &czcionka, sf::Vector2u size):czcionka1(czcionka) {
    wczytaj("../fonts/slowa.txt");
    //todo czy nie zamienic na stare C?
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,slowa.size());
    std::uniform_int_distribution<std::mt19937::result_type> dist3(1,3);
    for(int i = 0; i < 20; i++) {
        auto x = dist(rng);
        dodaj(Napis(slowa[x], 24, czcionka1, sf::Text::Bold, sf::Color::Cyan,
                    i * 25, dist3(rng)));
    }
    /*dodaj(Napis("pjatk", 24, czcionka1,
                       sf::Text::Bold, sf::Color::Cyan, 0, 1));
    dodaj(Napis("POPO", 24, czcionka1,
                       sf::Text::Bold, sf::Color::Red, 30, 2));*/
}

void Napisy::wczytaj(std::string nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    std::string linia;
    while(std::getline(plik, linia)) {
        slowa.push_back(linia);
    }
    plik.close();
}

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

bool Napisy::sprawdz(const std::string &slowo) {
    //todo zastanowic sie czy kasowac wszystkie wystapienia czy tylko jedno
        bool usuniete = false;
        for(auto itr = napisy.begin(); itr != napisy.end();) {
            if(itr->sprawdzSlowo(slowo)) {
                usuniete = true;
                itr = napisy.erase(itr);
            } else {
                ++itr;
            }
        }
        return usuniete;
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