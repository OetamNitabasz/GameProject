//
// Created by Mateusz Szabatin on 20.05.2024.
//
#include "Napisy.h"
#include <string>
#include <iostream>

sf::Font wczytajFont(const std::string& plik);

Napisy::Napisy() {
    //czcionka1 = wczytajFont("C:\\Windows\\Fonts\\Arial.ttf");
    czcionka1 = wczytajFont("../fonts/Roboto-Bold.ttf");
}
void Napisy::rysuj(sf::RenderWindow &window) {
    sf::Text tekst;
    tekst.setFont(czcionka1); //
    tekst.setStyle(sf::Text::Bold);
    tekst.setPosition(pozycjaX, 0);
    tekst.setString("PJATK");
    tekst.setCharacterSize(24);
    tekst.setFillColor(sf::Color::Cyan);
    window.draw(tekst);
}
sf::Font wczytajFont(const std::string& plik) {
    sf::Font font;
    if(!font.loadFromFile(plik)) {
        std::cerr << "blad wczytywania czcionki" << std::endl;
        //todo zastosowac wyjatki/przerwac program
    }
    return font;
}