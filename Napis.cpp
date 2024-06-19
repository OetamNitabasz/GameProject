//
// Created by mateu on 22.05.2024.
//

#include <SFML/Graphics.hpp>
#include "Napis.h"
#include "Napisy.h"

Napis::Napis(const Napis &napis):czcionka1(napis.czcionka1) {
    tekst = napis.tekst;
    speed = napis.speed;
    tekst.setFont(czcionka1);
    pozaEkranem = napis.pozaEkranem;
}

Napis::Napis(const std::string napis, unsigned int rozmiar, sf::Font& czcionka, sf::Text::Style styl,
             sf::Color kolor, float y, float predkosc): czcionka1(czcionka) {


    tekst.setString(napis);
    tekst.setCharacterSize(rozmiar);

    tekst.setStyle(styl);
    tekst.setFillColor(kolor);
    tekst.setPosition(0, y);
    speed = predkosc;
}

bool Napis::zaEkranem() {
    return pozaEkranem;
}

bool Napis::rysuj(sf::RenderWindow &window) {
    tekst.move(speed,0);
    if(tekst.getPosition().x > window.getSize().x) {
        pozaEkranem = true;
        return false;
    }
    window.draw(tekst);
    return true;
}

bool Napis::sprawdzSlowo(const std::string &slowo) const {
    std::string result;
    result.resize(slowo.size());
    std::transform(slowo.begin(), slowo.end(), result.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    //todo przeniesc do konstruktora
    std::string txt = tekst.getString();
    std::transform(txt.begin(), txt.end(), txt.begin(), [](unsigned char c){
        return std::tolower(c);
    });

    return result == txt;
}
