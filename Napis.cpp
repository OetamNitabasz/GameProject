//
// Created by mateu on 22.05.2024.
//

#include <SFML/Graphics.hpp>
#include "Napis.h"

void zmniejsz(std::string &txt) {
    std::transform(txt.begin(), txt.end(), txt.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

Napis::Napis(const Napis &napis):czcionka1(napis.czcionka1) {
    tekst = napis.tekst;
    speed = napis.speed;
    tekst.setFont(czcionka1);
    lowerCase = napis.lowerCase;
}

Napis::Napis(const std::string napis, unsigned int rozmiar, sf::Font& czcionka, sf::Text::Style styl,
             sf::Color kolor, float y, float predkosc): czcionka1(czcionka) {

    tekst.setString(napis);
    tekst.setCharacterSize(rozmiar);

    tekst.setStyle(styl);
    tekst.setFillColor(kolor);
    tekst.setPosition(0, y);
    speed = predkosc;

    lowerCase = tekst.getString();
    zmniejsz(lowerCase);
}

float Napis::poziom() {
    return tekst.getPosition().y;
}

bool Napis::rysuj(sf::RenderWindow &window) {
    tekst.move(speed,0);
    if(tekst.getPosition().x > window.getSize().x) {
        return false;
    }
    window.draw(tekst);
    return true;
}

int Napis::punktacja() {
    return tekst.getString().getSize();
}


int Napis::sprawdzSlowo(const std::string &slowo) {
    std::string result;
    result.resize(slowo.size());
    std::transform(slowo.begin(), slowo.end(), result.begin(), [](unsigned char c){
        return std::tolower(c);
    });


    if(result != lowerCase)
        return 0;
    else
        return punktacja();
}
