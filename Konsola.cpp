//
// Created by Mateusz Szabatin on 19.06.2024.
//
#include "Konsola.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Napisy.h"

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

    ustawPredkosc(1);
    predkosc.setCharacterSize(16);
    predkosc.setFillColor(sf::Color::Red);
    predkosc.setPosition(p.x + 600, p.y + 3);
    predkosc.setFont(czcionka1);

    ustawWielkosc(Srednie);
    wielkosc.setFillColor(sf::Color::Red);
    wielkosc.setPosition(p.x + 400, p.y + 3);
    wielkosc.setFont(czcionka1);
    wielkosc.setString("A");
}

void Konsola::wyswietl(sf::RenderWindow &window) {
    window.draw(panel);
    window.draw(tekst);
    window.draw(points);
    window.draw(predkosc);
    window.draw(wielkosc);
}

void Konsola::ustawSlowo(const std::string &slowo) {
    tekst.setString(slowo);
}


void Konsola::ustawPunktacje(float numb) {
    points.setString(std::to_string(numb));
}

void Konsola::ustawWielkosc(WielkoscNapisu rozmiar) {
    switch (rozmiar) {
        case Male : wielkosc.setCharacterSize(8); break;
        case Srednie : wielkosc.setCharacterSize(16); break;
        case Duze : wielkosc.setCharacterSize(24); break;
        default: wielkosc.setCharacterSize(16); break;
    }
}

void Konsola::ustawPredkosc(float szybkosc) {
    predkosc.setString(std::to_string(szybkosc));
}