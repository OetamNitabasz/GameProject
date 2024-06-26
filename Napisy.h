//
// Created by Mateusz Szabatin on 20.05.2024.
//

#ifndef GAMEPROJECT_NAPISY_H
#define GAMEPROJECT_NAPISY_H

#include <SFML/Graphics.hpp>
#include "Napis.h"
#include "Czcionki.h"
#include <list>
#include <random>
enum WielkoscNapisu {
    Male,
    Srednie,
    Duze
};

class Napisy {
public:
    Napisy(Czcionki &czcionki);
    void wyswietl(sf::RenderWindow& window);
    int zgubioneNapisy();
    bool sprawdz(const std::string &slowo);
    float punktacja();
    void ustawWielkosc(WielkoscNapisu nowyRozmiar);
    void przyspiesz();
    void zwolnij();
    float predkosc();
    WielkoscNapisu wielkoscNapisow();
    void zapisz();
    void wczytaj();

private:
    Napis generujNapis(float offsetY);
    void wczytaj(std::string plik);

    WielkoscNapisu rozmiar;

    float bazowaPredkosc = 1;
    float punkty = 0;
    std::mt19937 rng;
    std::vector<std::string> slowa;
    Czcionki &czcionki;
    std::list<Napis> napisy;
    int zgubione = 0;

};

#endif //GAMEPROJECT_NAPISY_H