#include "BarszczSosnowskiego.h"
#include "Pole.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego() {
	this->sila = 10;
	this->wiek = 0;
}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, Polozenie xy) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 10;
	this->wiek = 0;
}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, Polozenie xy, int wiek) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 10;
	this->wiek = wiek;
}

void BarszczSosnowskiego::sprawdzIZasiej(int x1, int y1) {
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
		this->swiat->dodajOrganizm(new BarszczSosnowskiego(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void BarszczSosnowskiego::sprawdzIZabij(int x1, int y1) {
	string komentarz;
	if (dynamic_cast<Zwierze*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		komentarz = "";
		komentarz += this->swiat->plansza[this->xy.x + x1][this->xy.y + y1]->getNazwa();
		komentarz += this->swiat->plansza[this->xy.x + x1][this->xy.y + y1]->getXY();
		komentarz += " zabity(a) przez ";
		komentarz += this->getNazwa();
		komentarz += this->getXY();
		this->swiat->dziennik(komentarz);
		this->swiat->plansza[this->xy.x + x1][this->xy.y + y1] = new Pole();
		for (int i = 0; i < this->swiat->organizmy.size(); i++) {
			if (this->swiat->organizmy[i]->getPolozenie().x == this->xy.x + x1 && this->swiat->organizmy[i]->getPolozenie().y == this->xy.y + y1) {
				this->swiat->organizmy.erase(this->swiat->organizmy.begin() + i);
			}
		}
	}
}

void BarszczSosnowskiego::rysowanie() {
	cout << 'b';
}

void BarszczSosnowskiego::zabijOkolice() {
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			sprawdzIZabij(0, 1);
			sprawdzIZabij(1, 1);
			sprawdzIZabij(1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			sprawdzIZabij(0, -1);
			sprawdzIZabij(1, -1);
			sprawdzIZabij(1, 0);
		}
		else {
			sprawdzIZabij(0, -1);
			sprawdzIZabij(1, -1);
			sprawdzIZabij(1, 0);
			sprawdzIZabij(0, 1);
			sprawdzIZabij(1, 1);
		}
	}
	else if (this->xy.x == this->swiat->getWysokosc() - 1) {
		if (this->xy.y == 0) {
			sprawdzIZabij(0, 1);
			sprawdzIZabij(-1, 1);
			sprawdzIZabij(-1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			sprawdzIZabij(0, -1);
			sprawdzIZabij(-1, -1);
			sprawdzIZabij(-1, 0);
		}
		else {
			sprawdzIZabij(0, 1);
			sprawdzIZabij(-1, 1);
			sprawdzIZabij(-1, 0);
			sprawdzIZabij(0, -1);
			sprawdzIZabij(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		sprawdzIZabij(0, 1);
		sprawdzIZabij(-1, 1);
		sprawdzIZabij(-1, 0);
		sprawdzIZabij(1, 1);
		sprawdzIZabij(1, 0);
	}
	else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
		sprawdzIZabij(0, -1);
		sprawdzIZabij(-1, -1);
		sprawdzIZabij(-1, 0);
		sprawdzIZabij(1, -1);
		sprawdzIZabij(1, 0);
	}
	else {
		sprawdzIZabij(0, 1);
		sprawdzIZabij(1, 0);
		sprawdzIZabij(1, 1);
		sprawdzIZabij(-1, 0);
		sprawdzIZabij(-1, 1);
		sprawdzIZabij(-1, -1);
		sprawdzIZabij(0, -1);
		sprawdzIZabij(1, -1);
	}
}

void BarszczSosnowskiego::akcja() {
	zabijOkolice();
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

void BarszczSosnowskiego::kolizja(Organizm* org) {
	string komentarz = "";
	komentarz += org->getNazwa();
	komentarz += " zjada ";
	komentarz += this->getNazwa();
	komentarz += " i umiera";
	swiat->dziennik(komentarz);
	swiat->plansza[this->xy.x][this->xy.y] = new Pole();
	swiat->plansza[org->getPolozenie().y][org->getPolozenie().x] = new Pole();
}

string BarszczSosnowskiego::getNazwa() {
	return "Barszcz_sosnowskiego";
}

BarszczSosnowskiego::~BarszczSosnowskiego() {
	
}