#include "Antylopa.h"
#include "Pole.h"

Antylopa::Antylopa() {
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 0;
}

Antylopa::Antylopa(Swiat* swiat, Polozenie xy) {
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 0;
	this->swiat = swiat;
	this->xy = xy;
}

Antylopa::Antylopa(Swiat* swiat, Polozenie xy, int sila, int wiek) {
	this->sila = sila;
	this->inicjatywa = 4;
	this->wiek = wiek;
	this->swiat = swiat;
	this->xy = xy;
}

void Antylopa::narodziny(int x1, int y1) {
	if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		string komentarz = "";
		komentarz += "Narodziny organizmu: ";
		komentarz += this->getNazwa();
		komentarz += "(";
		komentarz += to_string(this->xy.x + x1 + 1);
		komentarz += ",";
		komentarz += to_string(this->xy.y + y1 + 1);
		komentarz += ")";
		this->swiat->dziennik(komentarz);
		this->swiat->dodajOrganizm(new Antylopa(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Antylopa::akcja() {
	int los;
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			los = rand() % 5;
			if (los == 0) ruch(0, 1);
			else if (los == 1) ruch(1, 1);
			else if (los == 2) ruch(1, 0);
			else if (los == 3) ruch(0, 2);
			else if (los == 4) ruch(2, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			los = rand() % 5;
			if (los == 0) ruch(0, -1);
			else if (los == 1) ruch(1, -1);
			else if (los == 2) ruch(1, 0);
			else if (los == 3) ruch(0, -2);
			else if (los == 4) ruch(2, 0);
		}
		else {
			los = rand() % 8;
			if (los == 0) ruch(0, -1);
			else if (los == 1) ruch(1, -1);
			else if (los == 2) ruch(1, 0);
			else if (los == 3) ruch(0, 1);
			else if (los == 4) ruch(1, 1);
			else if (los == 5 && this->xy.y != this->swiat->getSzerokosc() - 2) ruch(0, 2);
			else if (los == 6 && this->xy.x != this->swiat->getWysokosc() - 2) ruch(2, 0);
			else if (los == 7 && this->xy.y != 1) ruch(0, -2);
		}
	}
	else if (this->xy.x == this->swiat->getWysokosc() - 1) {
		if (this->xy.y == 0) {
			los = rand() % 5;
			if (los == 0) ruch(0, 1);
			else if (los == 1) ruch(-1, 1);
			else if (los == 2) ruch(-1, 0);
			else if (los == 3) ruch(-2, 0);
			else if (los == 4) ruch(0, 2);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			los = rand() % 5;
			if (los == 0) ruch(0, -1);
			else if (los == 1) ruch(-1, -1);
			else if (los == 2) ruch(-1, 0);
			else if (los == 3) ruch(-2, 0);
			else if (los == 4) ruch(0, -2);
		}
		else {
			los = rand() % 8;
			if (los == 0) ruch(0, 1);
			else if (los == 1) ruch(-1, 1);
			else if (los == 2) ruch(-1, 0);
			else if (los == 3) ruch(0, -1);
			else if (los == 4) ruch(-1, -1);
			else if (los == 5 && this->xy.y != this->swiat->getSzerokosc() - 2) ruch(0, 2);
			else if (los == 6 && this->xy.x != 1) ruch(-2, 0);
			else if (los == 7 && this->xy.y != 1) ruch(0, -2);
		}
	}
	else if (this->xy.y == 0) {
		los = rand() % 8;
		if (los == 0) ruch(0, 1);
		else if (los == 1) ruch(-1, 1);
		else if (los == 2) ruch(-1, 0);
		else if (los == 3) ruch(1, 1);
		else if (los == 4) ruch(1, 0);
		else if (los == 5) ruch(0, 2);
		else if (los == 6 && this->xy.x != 1) ruch(-2, 0);
		else if (los == 7 && this->xy.x != this->swiat->getWysokosc() - 2) ruch(2, 0);
	}
	else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
		los = rand() % 8;
		if (los == 0) ruch(0, -1);
		else if (los == 1) ruch(-1, -1);
		else if (los == 2) ruch(-1, 0);
		else if (los == 3) ruch(1, -1);
		else if (los == 4) ruch(1, 0);
		else if (los == 5) ruch(0, -2);
		else if (los == 6 && this->xy.x != 1) ruch(-2, 0);
		else if (los == 7 && this->xy.x != this->swiat->getWysokosc() - 2) ruch(2, 0);
	}
	else {
		los = rand() % 12;
		if (los == 0) ruch(0, 1);
		else if (los == 1) ruch(1, 0);
		else if (los == 2) ruch(1, 1);
		else if (los == 3) ruch(-1, 0);
		else if (los == 4) ruch(-1, 1);
		else if (los == 5) ruch(-1, -1);
		else if (los == 6) ruch(0, -1);
		else if (los == 7) ruch(1, -1);
		else if (los == 8 && this->xy.x != 1) ruch(-2, 0);
		else if (los == 9 && this->xy.x != this->swiat->getWysokosc() - 2) ruch(2, 0);
		else if (los == 10 && this->xy.y != this->swiat->getSzerokosc() - 2) ruch(0, 2);
		else if (los == 11 && this->xy.y != 1) ruch(0, -2);
	}
}

void Antylopa::kolizja(Organizm* org) {
	int szansa = rand() % 2;
	if (dynamic_cast<Antylopa*>(org)) {
		if (this->wiek > 2) rozmnazanie();
	}
	else if (szansa == 0) {
		string komentarz = "";
		komentarz += this->getNazwa();
		komentarz += this->getXY();
		komentarz += " ucieka.";
		this->swiat->dziennik(komentarz);
		if (this->xy.y != swiat->getSzerokosc() - 1 && dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x][this->xy.y + 1])) {
			swiat->plansza[this->xy.x][this->xy.y + 1] = swiat->plansza[this->xy.x][this->xy.y];
			swiat->plansza[this->xy.x][this->xy.y] = new Pole();
			this->xy.y++;
		}
		else if (this->xy.x != swiat->getWysokosc() - 1 && dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + 1][this->xy.y])) {
			swiat->plansza[this->xy.x + 1][this->xy.y] = swiat->plansza[this->xy.x][this->xy.y];
			swiat->plansza[this->xy.x][this->xy.y] = new Pole();
			this->xy.x++;
		}
		else if (this->xy.y != 0 && dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x][this->xy.y - 1])) {
			swiat->plansza[this->xy.x][this->xy.y - 1] = swiat->plansza[this->xy.x][this->xy.y];
			swiat->plansza[this->xy.x][this->xy.y] = new Pole();
			this->xy.y--;
		}
		else if (this->xy.x != 0 && dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x - 1][this->xy.y])) {
			swiat->plansza[this->xy.x - 1][this->xy.y] = swiat->plansza[this->xy.x][this->xy.y];
			swiat->plansza[this->xy.x][this->xy.y] = new Pole();
			this->xy.x--;
		}
	}
	else if (org->getSila() > this->sila) {
		string komentarz = "";
		komentarz += org->getNazwa();
		komentarz += org->getXY();
		komentarz += " pokonuje ";
		komentarz += this->getNazwa();
		komentarz += this->getXY();
		swiat->dziennik(komentarz);
		for (int i = 0; i < this->swiat->organizmy.size(); i++) {
			if (this->swiat->organizmy[i]->getPolozenie().x == this->xy.x && this->swiat->organizmy[i]->getPolozenie().y == this->xy.y) {
				this->swiat->organizmy.erase(this->swiat->organizmy.begin() + i);
			}
		}
		swiat->plansza[this->xy.x][this->xy.y] = org;
		swiat->plansza[org->getPolozenie().x][org->getPolozenie().y] = new Pole();
		org->setX(this->xy.x);
		org->setY(this->xy.y);
	}
	else {
		string komentarz = "";
		komentarz += org->getNazwa();
		komentarz += org->getXY();
		komentarz += " przegrywa z ";
		komentarz += this->getNazwa();
		komentarz += this->getXY();
		swiat->dziennik(komentarz);
		swiat->plansza[org->getPolozenie().x][org->getPolozenie().y] = new Pole();
		for (int i = 0; i < this->swiat->organizmy.size(); i++) {
			if (this->swiat->organizmy[i]->getPolozenie().x == org->getPolozenie().x && this->swiat->organizmy[i]->getPolozenie().y == org->getPolozenie().y) {
				this->swiat->organizmy.erase(this->swiat->organizmy.begin() + i);
			}
		}
	}
}

void Antylopa::rysowanie() {
	cout << 'A';
}

string Antylopa::getNazwa() {
	return "Antylopa";
}

Antylopa::~Antylopa() {

}