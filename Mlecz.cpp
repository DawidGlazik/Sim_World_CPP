#include "Mlecz.h"
#include "Pole.h"

Mlecz::Mlecz() {
	this->sila = 0;
	this->wiek = 0;
}

Mlecz::Mlecz(Swiat* swiat, Polozenie xy) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 0;
	this->wiek = 0;
}

Mlecz::Mlecz(Swiat* swiat, Polozenie xy, int wiek) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 0;
	this->wiek = wiek;
}

void Mlecz::sprawdzIZasiej(int x1, int y1) {
	string komentarz;
	if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		komentarz = "";
		komentarz += "Zasiano ";
		komentarz += this->getNazwa();
		komentarz += "(";
		komentarz += to_string(this->xy.x + x1 + 1);
		komentarz += ",";
		komentarz += to_string(this->xy.y + +y1 + 1);
		komentarz += ")";
		this->swiat->dziennik(komentarz);
		this->swiat->dodajOrganizm(new Mlecz(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Mlecz::rysowanie() {
	cout << 'm';
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		int los1 = rand() % 15;
		int los2;
		if (los1 != 0) return;
		if (this->xy.x == 0) {
			los2 = rand() % 11;
			if (this->xy.y == 0 && los2 < 3) {
				if (los2 == 0) sprawdzIZasiej(0, 1);
				else if (los2 == 1) sprawdzIZasiej(1, 1);
				else if (los2 == 2)sprawdzIZasiej(1, 0);
			}
			else if (this->xy.y == this->swiat->getSzerokosc() - 1 && los2 < 6) {
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
			if (this->xy.y == 0 && los2 < 3) {
				if (los2 == 0) sprawdzIZasiej(0, 1);
				else if (los2 == 1) sprawdzIZasiej(-1, 1);
				else if (los2 == 2) sprawdzIZasiej(-1, 0);
			}
			else if (this->xy.y == this->swiat->getSzerokosc() - 1 && los2 < 6) {
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
}

string Mlecz::getNazwa() {
	return "Mlecz";
}

Mlecz::~Mlecz() {

}