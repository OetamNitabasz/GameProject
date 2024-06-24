//
// Created by Mateusz Szabatin on 20.05.2024.
//
#include "Napisy.h"
#include "Napis.h"
#include <string>
#include <iostream>
#include <fstream>
#include <random>

Napis generatorNapisu(const std::vector<std::string> &slowa, float offsetY, std::mt19937 &rng, sf::Font &czcionka) {
    std::uniform_int_distribution<std::mt19937::result_type> kolejneSlowo(1, slowa.size());
    std::uniform_int_distribution<std::mt19937::result_type> predkosc(1, 3);
    auto x = kolejneSlowo(rng) - 1;
    auto n = Napis(slowa[x], 24, czcionka, sf::Text::Bold, sf::Color::Cyan,
                   offsetY, predkosc(rng));
    return n;
}

Napisy::Napisy(sf::Font &czcionka, sf::Vector2u size):czcionka1(czcionka) {
    wczytaj("../fonts/slowa.txt");
    std::random_device dev;
    rng = std::mt19937(dev());
    for(int i = 0; i < 20; i++) {
        napisy.push_back(generatorNapisu(slowa, i * 25, rng, czcionka1));
    }
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
    for(auto i = napisy.begin(); i != napisy.end();) {
        if(!i->rysuj(window)) {
            zgubione++;
            auto offsetY = i->poziom();
            i = napisy.erase(i);
            napisy.insert(i, generatorNapisu(slowa, offsetY, rng, czcionka1));
        } else {
            ++i;
        }
    }
}

bool Napisy::sprawdz(const std::string &slowo) {
        bool usuniete = false;
        for(auto itr = napisy.begin(); itr != napisy.end();) {
            auto pkt = itr->sprawdzSlowo(slowo);
            if(pkt) {
                usuniete = true;
                auto offsetY = itr->poziom();
                itr = napisy.erase(itr);
                napisy.insert(itr, generatorNapisu(slowa, offsetY, rng, czcionka1));
                punkty += pkt;
            } else {
                ++itr;
            }
        }
        return usuniete;
}

int Napisy::zgubioneNapisy() {
    return zgubione;
}


sf::Font wczytajFont(const std::string& plik) {
    sf::Font font;
    if(!font.loadFromFile(plik)) {
        std::cerr << "blad wczytywania czcionki" << std::endl;
        //todo zastosowac wyjatki/przerwac program
    }
    return font;
}

int Napisy::punktacja() {
    return punkty;
}