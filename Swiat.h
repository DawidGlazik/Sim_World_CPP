#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Organizm.h"
using namespace std;

class Organizm;

class Swiat {
private:
	int tura;
	int szerokosc;
	int wysokosc;
	string konsola;
public:
	vector <Organizm*> organizmy;
	Organizm*** plansza;
	Swiat();
	Swiat(int szerokosc, int wysokosc);
	void zapisz();
	void wczytaj();
	void wykonajTure(int kierunek);
	void rysujSwiat();
	void dodajOrganizm(Organizm* nowy);
	void dziennik(string konsola);
	void wypiszOrganizmy();
	int getSzerokosc();
	int getWysokosc();
	void rozpocznijCalopalenie();
	~Swiat();
};