//
// Created by mateu on 22.05.2024.
//

#include <SFML/Graphics.hpp>
#include "Napis.h"
#include "Napisy.h"

Napis::Napis(const std::string napis, unsigned int rozmiar, sf::Font czcionka, sf::Text::Style styl,
             sf::Color kolor, float y, float predkosc) {
    czcionka1 = wczytajFont("../fonts/Roboto-Bold.ttf");

    tekst.setFont(czcionka1);
    /*//tekst = sf::Text(napis, czcionka1, rozmiar);
    tekst.setString(napis);
    tekst.setCharacterSize(rozmiar);

    tekst.setStyle(styl);
    tekst.setFillColor(kolor);
    tekst.setPosition(0, y);
    speed = predkosc;*/
}

void Napis::rysuj(sf::RenderWindow &window) {

    //czcionka1 = wczytajFont("../fonts/Roboto-Bold.ttf");
    //tekst = sf::Text(napis, czcionka1, rozmiar);
    tekst.setString("PJATK");
    tekst.setCharacterSize(24);
    //tekst.setFont(czcionka1);
    tekst.setStyle(sf::Text::Bold);
    tekst.setFillColor(sf::Color::Cyan);
    tekst.setPosition(0, 0);
    speed = 1;
    tekst.move(speed,0);
    window.draw(tekst);
}