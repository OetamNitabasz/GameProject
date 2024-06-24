//
// Created by Mateusz Szabatin on 19.06.2024.
//
#include "Konsola.h"
#include <SFML/Graphics.hpp>
#include <sstream>

Konsola::Konsola(float height, sf::Font &czcionka, sf::Vector2u windowSize): h(height), czcionka1(czcionka) {
    panel.setPosition(0, windowSize.y - h);
    panel.setSize(sf::Vector2f(windowSize.x, h));
    panel.setFillColor(sf::Color::Blue);

    auto p = panel.getPosition();
    tekst.setCharacterSize(25);
    tekst.setFillColor(sf::Color::Yellow);
    tekst.setPosition(p.x + 3, p.y + 3);
    tekst.setFont(czcionka1);

    ustawPunktacje(0);
    points.setCharacterSize(25);
    points.setFillColor(sf::Color::Green);
    points.setPosition(p.x + 750, p.y + 3);
    points.setFont(czcionka1);
}

void Konsola::wyswietl(sf::RenderWindow &window) {
    window.draw(panel);
    window.draw(tekst);
    window.draw(points);
}

void Konsola::ustawSlowo(const std::string &slowo) {
    tekst.setString(slowo);
}


void Konsola::ustawPunktacje(int numb) {
    points.setString(std::to_string(numb));

}


