#include "Roslina.h"
#include "Pole.h"

Roslina::Roslina() {
	this->sila = 0;
	this->inicjatywa = 0;
	this->xy = { 0,0 };
}

Roslina::Roslina(Swiat* swiat, Polozenie xy) {
	this->sila = 0;
	this->inicjatywa = 0;
	this->swiat = swiat;
	this->xy = xy;
}

void Roslina::sprawdzIZasiej(int x1, int y1) {
	string komentarz;
	if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		komentarz = "";
		komentarz += "Zasiano rosline";
		komentarz += "(";
		komentarz += to_string(this->xy.x + x1 + 1);
		komentarz += ",";
		komentarz += to_string(this->xy.y + + y1 + 1);
		komentarz += ")";
		this->swiat->dziennik(komentarz);
		this->swiat->dodajOrganizm(new Roslina(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Roslina::akcja() {
	int los1 = rand() % 15;
	int los2;
	if (los1 != 0) return;
	if (this->xy.x == 0) {
		los2 = rand() % 11;
		if (this->xy.y == 0) {
			if (los2 == 0) sprawdzIZasiej(0, 1);
			else if (los2 == 1) sprawdzIZasiej(1, 1);
			else if (los2 == 2)sprawdzIZasiej(1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			if (los2 == 3) sprawdzIZasiej(0, -1);
			else if (los2 == 4) sprawdzIZasiej(1, -1);
			else if (los2 == 5) sprawdzIZasiej(1, 0);
		}
		else {
			if (los2 == 6) sprawdzIZasiej(0, -1);
			else if (los2 == 7) sprawdzIZasiej(1, -1);
			else if (los2 == 8) sprawdzIZasiej(1, 0);
			else if (los2 == 9) sprawdzIZasiej(0, 1);
			else if (los2 == 10) sprawdzIZasiej(1, 1);
		}
	}
	else if (this->xy.x == this->swiat->getWysokosc() - 1) {
		los2 = rand() % 11;
		if (this->xy.y == 0) {
			if (los2 == 0) sprawdzIZasiej(0, 1);
			else if (los2 == 1) sprawdzIZasiej(-1, 1);
			else if (los2 == 2) sprawdzIZasiej(-1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			if (los2 == 3) sprawdzIZasiej(0, -1);
			else if (los2 == 4) sprawdzIZasiej(-1, -1);
			else if (los2 == 5) sprawdzIZasiej(-1, 0);
		}
		else {
			if (los2 == 6) sprawdzIZasiej(0, 1);
			else if (los2 == 7) sprawdzIZasiej(-1, 1);
			else if (los2 == 8) sprawdzIZasiej(-1, 0);
			else if (los2 == 9) sprawdzIZasiej(0, -1);
			else if (los2 == 10) sprawdzIZasiej(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		los2 = rand() % 5;
		if (los2 == 0) sprawdzIZasiej(0, 1);
		else if (los2 == 1) sprawdzIZasiej(-1, 1);
		else if (los2 == 2) sprawdzIZasiej(-1, 0);
		else if (los2 == 3) sprawdzIZasiej(1, 1);
		else if (los2 == 4) sprawdzIZasiej(1, 0);
	}
	else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
		los2 = rand() % 5;
		if (los2 == 0) sprawdzIZasiej(0, -1);
		else if (los2 == 1) sprawdzIZasiej(-1, -1);
		else if (los2 == 2) sprawdzIZasiej(-1, 0);
		else if (los2 == 3) sprawdzIZasiej(1, -1);
		else if (los2 == 4) sprawdzIZasiej(1, 0);
	}
	else {
		los2 = rand() % 8;
		if (los2 == 0) sprawdzIZasiej(0, 1);
		else if (los2 == 1) sprawdzIZasiej(1, 0);
		else if (los2 == 2) sprawdzIZasiej(1, 1);
		else if (los2 == 3) sprawdzIZasiej(-1, 0);
		else if (los2 == 4) sprawdzIZasiej(-1, 1);
		else if (los2 == 5) sprawdzIZasiej(-1, -1);
		else if (los2 == 6) sprawdzIZasiej(0, -1);
		else if (los2 == 7) sprawdzIZasiej(1, -1);
	}
}

void Roslina::kolizja(Organizm* org) {
	string komentarz = "";
	komentarz += org->getNazwa();
	komentarz += org->getXY();
	komentarz += " zjada ";
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

void Roslina::rysowanie() {
	cout << 'r';
}

string Roslina::getNazwa() {
	return "Roslina";
}

Roslina::~Roslina() {

}