//
// Created by Mateusz Szabatin on 26.06.2024.
//
#include "Czcionki.h"
#include <iostream>

Czcionki::Czcionki() {
    wczytajFont("../fonts/Roboto/Roboto-Bold.ttf");
    wczytajFont("../fonts/Bebas_Neue/BebasNeue-Regular.ttf");
    wczytajFont("../fonts/Playwrite_IT_Moderna/PlaywriteITModerna-VariableFont_wght.ttf");
    wczytajFont("../fonts/Roboto/Roboto-ThinItalic.ttf");
}

void Czcionki::wczytajFont(const std::string& plik) {
    sf::Font font;
    if(!font.loadFromFile(plik)) {
        std::cerr << "blad wczytywania czcionki" << std::endl;
        //todo zastosowac wyjatki/przerwac program
    }
    fonts.push_back(font);
}

sf::Font &Czcionki::dajPodstawowy() {
    return fonts[0];
}

sf::Font &Czcionki::dajLosowy(std::mt19937 &rng) {
    std::uniform_int_distribution<std::mt19937::result_type> kolejnaCzcionka(1, fonts.size());
    return fonts[kolejnaCzcionka(rng) - 1];
}

sf::Font &Czcionki::daj(const std::string &familiy) {
    for(int i = 0; i < fonts.size(); ++i) {
        if(familiy == fonts[i].getInfo().family) {
            return fonts[i];
        }
    }
    return dajPodstawowy();
}