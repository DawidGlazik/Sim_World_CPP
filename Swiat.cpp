#include "Organizm.h"
#include <iostream>
using namespace std;
#include <Windows.h>
#include "Organizmy.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>

Swiat::Swiat() {
	this->tura = 0;
	this->konsola = "";
}

Swiat::Swiat(const int szerokosc, const int wysokosc) {
	this->tura = 0;
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
	this->konsola = "";
	this->organizmy.reserve(szerokosc * wysokosc);
	plansza = new Organizm** [wysokosc];
	for (int i = 0; i < wysokosc; i++) {
		plansza[i] = new Organizm * [szerokosc];
	}
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) plansza[i][j] = new Pole(this, {j, i});
	}

	srand(time(NULL));
	int random1, random2, random3, numberOfOrganisms, k;
	numberOfOrganisms = szerokosc * wysokosc / 15;
	Czlowiek* czlowiek = new Czlowiek(this, { wysokosc / 2, szerokosc / 2 });
	dodajOrganizm(czlowiek);
	for (int i = 0; i < numberOfOrganisms; i++) {
		random1 = rand() % wysokosc;
		random2 = rand() % szerokosc;
		random3 = rand() % 1000;
		if (dynamic_cast<Pole*>(plansza[random1][random2])) {
			if (i < 10) {
				k = i;
			}
			else {
				k = random3 % 10;
			}
			switch (k)
			{
			case 0:
				dodajOrganizm(new BarszczSosnowskiego(this, { random1, random2 }));
				break;
			case 1:
				dodajOrganizm(new Guarana(this, { random1, random2 }));
				break;
			case 2:
				dodajOrganizm(new Mlecz(this, { random1, random2 }));
				break;
			case 3:
				dodajOrganizm(new Trawa(this, { random1, random2 }));
				break;
			case 4:
				dodajOrganizm(new WilczeJagody(this, { random1, random2 }));
				break;
			case 5:
				dodajOrganizm(new Antylopa(this, { random1, random2 }));
				break;
			case 6:
				dodajOrganizm(new Lis(this, { random1, random2 }));
				break;
			case 7:
				dodajOrganizm(new Owca(this, { random1, random2 }));
				break;
			case 8:
				dodajOrganizm(new Wilk(this, { random1, random2 }));
				break;
			case 9:
				dodajOrganizm(new Zolw(this, { random1, random2 }));
				break;
			default:
				break;
			}
		}
	}
}

void Swiat::rozpocznijCalopalenie() {
	for (int i = 0; i < organizmy.size(); i++) {
		if (dynamic_cast<Czlowiek*> (organizmy[i])) {
			Czlowiek* tmp = dynamic_cast<Czlowiek*> (organizmy[i]);
			if (tmp->getTrwanie() == 5) {
				string komentarz = "Czlowiek rozpoczyna calopalenie.";
				this->dziennik(komentarz);
				tmp->calopalenie();
				if (tmp->getPrzerwa() != 5) tmp->addPrzerwa(5);
			}
		}
	}
}

void Swiat::wykonajTure(int kierunek) {
	for (int i = 0; i < organizmy.size(); i++) {
		if (dynamic_cast<Czlowiek*>(organizmy[i])) {
			Czlowiek* tmp = dynamic_cast<Czlowiek*>(organizmy[i]);
			tmp->akcja(kierunek);
			if (tmp->getTrwanie() < 5 && tmp->getTrwanie() > 0) {
				tmp->calopalenie();
			}
			else if (tmp->getPrzerwa() > 0) {
				tmp->addPrzerwa(-1);
			}
			else {
				tmp->setTrwanie(5);
			}
		}
		else if (dynamic_cast<BarszczSosnowskiego*>(organizmy[i])) {
			BarszczSosnowskiego* tmp = dynamic_cast<BarszczSosnowskiego*>(organizmy[i]);
			tmp->akcja();
		}
		else organizmy[i]->akcja();

	}
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->addWiek(1);
	}
	this->tura++;
}

void Swiat::rysujSwiat() {
	system("cls");
	cout << "Dawid Glazik 193069\tenter - kolejna tura, q - wyjdz, c - calopalenie, \nstrzalki - ruch czlowieka, s - zapisz, l - wczytaj" << endl;
	for (int i = 0; i < szerokosc + 2; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < this->wysokosc; i++) {
		cout << "|";
		for (int k = 0; k < this->szerokosc; k++) {
			plansza[i][k]->rysowanie();
		}
		cout << "|";
		cout << endl;
	}
	for (int i = 0; i < szerokosc + 2; i++) {
		cout << "-";
	}
	cout << "\nTura(" << this->tura << ").dziennik: " << endl;
	for (int i = 0; i < organizmy.size(); i++) {
		if (dynamic_cast<Czlowiek*>(organizmy[i])) {
			Czlowiek* tmp = dynamic_cast<Czlowiek*>(organizmy[i]);
			if (tmp->getTrwanie() !=0 && tmp->getTrwanie() != 5) cout << "Calopalenie aktywne jeszcze przez: " << tmp->getTrwanie() << " tur(y)." << endl;
			if (tmp->getTrwanie() == 0 && tmp->getPrzerwa() != 0)cout << "Calopalenie dostepne za " << tmp->getPrzerwa() << " tur(y)." << endl;
		}
	}
	cout << this->konsola;
	this->konsola = "";
	//wypiszOrganizmy();
}

void Swiat::dodajOrganizm(Organizm* nowy) {
	this->plansza[nowy->getPolozenie().x][nowy->getPolozenie().y] = nowy;
	if (organizmy.size() == 0) organizmy.push_back(nowy);
	else {
		for (int i=0;i<organizmy.size();i++){
			if (nowy->getInicjatywa() > organizmy[i]->getInicjatywa()) {
				auto indeks = find(organizmy.begin(), organizmy.end(), organizmy[i]);
				organizmy.insert(indeks, nowy);
				return;
			}
		}
		organizmy.push_back(nowy);
	}
}

void Swiat::wypiszOrganizmy() {
	for (int i = 0; i < organizmy.size(); i++) {
		cout << organizmy[i]->getNazwa() << " - ";
	}
}

void Swiat::dziennik(string konsola) {
	this->konsola += konsola;
	this->konsola += "\n";
}

int Swiat::getSzerokosc() {
	return szerokosc;
}

int Swiat::getWysokosc() {
	return wysokosc;
}

void Swiat::zapisz() {
	fstream plik;
	string nazwa;
	cout << "Podaj nazwe pliku do zapisu: "; 
	cin >> nazwa;
	plik.open(nazwa, ios::out);
	if (plik.good() == true)
	{
		plik << this->tura << " " << this->szerokosc << " " << this->wysokosc << " " << organizmy.size() << endl;
		for (int i = 0; i < organizmy.size(); i++) {
			plik << organizmy[i]->getNazwa() << " " << organizmy[i]->getPolozenie().x << " " << organizmy[i]->getPolozenie().y << " " << organizmy[i]->getSila() << " " << organizmy[i]->getWiek() << " ";
			if (dynamic_cast<Czlowiek*>(organizmy[i])) {
				Czlowiek* tmp = dynamic_cast<Czlowiek*> (organizmy[i]);
				plik << tmp->getTrwanie() << " " << tmp->getPrzerwa();
			}
			plik << endl;
		}
		plik.close();
	}
}

void Swiat::wczytaj() {
	fstream plik;
	string nazwa;
	cout << "Podaj nazwe pliku do odczytu: ";
	cin >> nazwa;
	plik.open(nazwa, ios::in);
	if (plik.good() == true)
	{
		int rozmiar;
		string nazwa;
		int x, y, wiek, sila, przerwa, trwanie;
		for (int i = 0; i < wysokosc; i++) delete plansza[i];
		delete[] plansza;
		organizmy.clear();
		plik >> this->tura >> this->szerokosc >> this->wysokosc >> rozmiar;
		this->organizmy.reserve(szerokosc * wysokosc);
		plansza = new Organizm * *[wysokosc];
		for (int i = 0; i < wysokosc; i++) {
			plansza[i] = new Organizm * [szerokosc];
		}
		for (int i = 0; i < wysokosc; i++) {
			for (int  j= 0; j < szerokosc; j++) plansza[i][j] = new Pole(this, { j, i });
		}
		for (int i = 0; i < rozmiar; i++) {
			plik >> nazwa >> x >> y >> wiek >> sila;
			if (nazwa == "Barszcz_sosnowskiego") {
				dodajOrganizm(new BarszczSosnowskiego(this, { x, y }, wiek));
			}
			else if (nazwa == "Guarana") {
				dodajOrganizm(new Guarana(this, { x, y }, wiek));
			}
			else if (nazwa == "Mlecz") {
				dodajOrganizm(new Mlecz(this, { x, y }, wiek));
			}
			else if (nazwa == "Trawa") {
				dodajOrganizm(new Trawa(this, { x, y }, wiek));
			}
			else if (nazwa == "Wilcze_jagody") {
				dodajOrganizm(new WilczeJagody(this, { x, y }, wiek));
			}
			else if (nazwa == "Antylopa") {
				dodajOrganizm(new Antylopa(this, { x, y }, sila, wiek));
			}
			else if (nazwa == "Lis") {
				dodajOrganizm(new Lis(this, { x, y }, sila, wiek));
			}
			else if (nazwa == "Owca") {
				dodajOrganizm(new Owca(this, { x, y }, sila, wiek));
			}
			else if (nazwa == "Wilk") {
				dodajOrganizm(new Wilk(this, { x, y }, sila, wiek));
			}
			else if (nazwa == "Zolw") {
				dodajOrganizm(new Zolw(this, { x, y }, sila, wiek));
			}
			else if (nazwa == "Czlowiek") {
				plik >> trwanie >> przerwa;
				dodajOrganizm(new Czlowiek(this, { x, y }, sila, wiek, trwanie, przerwa));
			}
		}
		plik.close();
	}
}

Swiat::~Swiat() {
	for (int i = 0; i < this->wysokosc; i++) {
		delete[] plansza[i];
	}
	delete[] plansza;
}