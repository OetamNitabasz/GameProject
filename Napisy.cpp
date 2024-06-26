//
// Created by Mateusz Szabatin on 20.05.2024.
//
#include "Napisy.h"
#include "Napis.h"
#include <string>
#include <fstream>
#include <random>
#include <fstream>

Napisy::Napisy(Czcionki &czcionki1): czcionki(czcionki1), rozmiar(Srednie) {
    wczytaj("../fonts/slowa.txt");
    std::random_device dev;
    rng = std::mt19937(dev());
    for(int i = 0; i < 20; i++) {
        napisy.push_back(generujNapis(i * 25));
    }
}

int wielkosc(WielkoscNapisu rozmiar) {
    switch (rozmiar) {
        case Male : return 8;
        case Srednie : return 16;
        case Duze : return 24;
        default: return 16;
    }
}

Napis Napisy::generujNapis(float offsetY) {
    std::uniform_int_distribution<std::mt19937::result_type> kolejneSlowo(1, slowa.size());
    std::uniform_int_distribution<std::mt19937::result_type> predkosc(1, 3);
    std::uniform_int_distribution<std::mt19937::result_type> kolor(15,240);
    auto x = kolejneSlowo(rng) - 1;
    auto p = static_cast<float>(predkosc(rng)) * bazowaPredkosc;
    auto k = sf::Color(kolor(rng), kolor(rng), kolor(rng));
    auto n = Napis(slowa[x], wielkosc(rozmiar), czcionki.dajLosowy(rng), k,
                  0 ,offsetY, p);
    return n;
}

void Napisy::przyspiesz() {
    if(bazowaPredkosc >= 10)
        return;

    bazowaPredkosc += 0.1;
}

void Napisy::zwolnij() {
    if(bazowaPredkosc <= 0.5)
        return;

    bazowaPredkosc -= 0.1;
}

float Napisy::predkosc() {
    return bazowaPredkosc;
}

WielkoscNapisu Napisy::wielkoscNapisow() {
    return rozmiar;
}

void Napisy::ustawWielkosc(WielkoscNapisu nowyRozmiar) {
    rozmiar = nowyRozmiar;
    std::for_each(napisy.begin(), napisy.end(), [&](Napis &n){
        n.ustawRozmiar(wielkosc(rozmiar));
    });
}

void Napisy::wczytaj(std::string nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    std::string linia;
    while(std::getline(plik, linia)) {
        slowa.push_back(linia);
    }
    plik.close();
}

void Napisy::wyswietl(sf::RenderWindow &window) {
    for(auto i = napisy.begin(); i != napisy.end();) {
        if(!i->rysuj(window)) {
            zgubione++;
            auto offsetY = i->poziom();
            i = napisy.erase(i);
            napisy.insert(i, generujNapis(offsetY));
        } else {
            ++i;
        }
    }
}

bool Napisy::sprawdz(const std::string &slowo) {
        bool usuniete = false;
        for(auto itr = napisy.begin(); itr != napisy.end();) {
            float pkt = itr->sprawdzSlowo(slowo);
            if(pkt > 0) {
                usuniete = true;
                auto offsetY = itr->poziom();
                itr = napisy.erase(itr);
                napisy.insert(itr, generujNapis(offsetY));
                punkty += pkt * bazowaPredkosc;
            } else {
                ++itr;
            }
        }
        return usuniete;
}

int Napisy::zgubioneNapisy() {
    return zgubione;
}


float Napisy::punktacja() {
    return punkty;
}

void Napisy::zapisz() {
    auto p = std::ofstream("Game.sav", std::ios_base::out | std::ios_base::trunc);
    p << bazowaPredkosc << std::endl
    << rozmiar << std::endl
    << punkty << std::endl
    << zgubione << std::endl;
    std::for_each(napisy.begin(), napisy.end(), [&](Napis &n){
        n.zapisz(p);
    });
    p.close();
}

void Napisy::wczytaj() {
    auto p = std::ifstream("Game.sav");
    if(!p.is_open())
        return;
    std::string linia;
    std::getline(p, linia);
    bazowaPredkosc = std::stof(linia);
    std::getline(p, linia);
    rozmiar = static_cast<WielkoscNapisu>(std::stoi(linia));
    std::getline(p, linia);
    punkty = std::stof(linia);
    std::getline(p, linia);
    zgubione = std::stoi(linia);
    napisy.clear();
    while(std::getline(p, linia)) {
        Napis napis = Napis::wczytaj(linia, czcionki);
        napisy.push_back(napis);
    }
}