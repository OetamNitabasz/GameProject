//
// Created by Mateusz Szabatin on 19.06.2024.
//
#include "Konsola.h"
#include <SFML/Graphics.hpp>

Konsola::Konsola(float height, sf::Font &czcionka, sf::Vector2u windowSize): h(height), czcionka1(czcionka) {
    panel.setPosition(0, windowSize.y - h);
    panel.setSize(sf::Vector2f(windowSize.x, h));
    panel.setFillColor(sf::Color::Blue);

    auto p = panel.getPosition();
    tekst.setCharacterSize(25);
    tekst.setFillColor(sf::Color::Yellow);
    tekst.setPosition(p.x + 3, p.y + 3);
    tekst.setFont(czcionka1);
}

void Konsola::wyswietl(sf::RenderWindow &window) {
    window.draw(panel);
    window.draw(tekst);
}

void Konsola::ustawSlowo(const std::string &slowo) {
    tekst.setString(slowo);
}