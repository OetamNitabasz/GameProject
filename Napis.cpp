//
// Created by mateu on 22.05.2024.
//

#include <SFML/Graphics.hpp>
#include <sstream>
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



Napis::Napis(const std::string napis, unsigned int rozmiar, sf::Font& czcionka,
             sf::Color kolor, float x, float y, float predkosc): czcionka1(czcionka) {

    tekst.setString(napis);
    tekst.setCharacterSize(rozmiar);

    tekst.setFillColor(kolor);
    tekst.setPosition(x, y);
    speed = predkosc;

    lowerCase = tekst.getString();
    zmniejsz(lowerCase);
}

void Napis::ustawRozmiar(int wielkosc) {
    tekst.setCharacterSize(wielkosc);
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

float Napis::punktacja() {
    return static_cast<float> (tekst.getString().getSize());
}


float Napis::sprawdzSlowo(const std::string &slowo) {
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

void Napis::zapisz(std::ostream &plik) {
    plik << tekst.getPosition().x << ","
    << tekst.getPosition().y << ","
    << tekst.getFillColor().toInteger() << ","
    << tekst.getFont()->getInfo().family << ","
    << speed << ","
    << tekst.getCharacterSize() << ","
    << tekst.getString().toAnsiString() << std::endl;
}

Napis Napis::wczytaj(const std::string &linia, Czcionki &czcionki) {
    auto ss = std::stringstream(linia);
    std::string slowo;
    std::vector<std::string> dane;
    while(!ss.eof()) {
        std::getline(ss, slowo, ',');
        dane.push_back(slowo);
    }
    auto napis = Napis(dane[6], std::stoi(dane[5]), czcionki.daj(dane[3]),
                       sf::Color(std::stoul(dane[2])),
                       std::stof(dane[0]) ,std::stof(dane[1]), std::stof(dane[4]));
    return napis;
}

