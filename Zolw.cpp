#include "Zolw.h"
#include "Pole.h"

Zolw::Zolw() {
	this->sila = 2;
	this->inicjatywa = 1;
	this->wiek = 0;
}

Zolw::Zolw(Swiat* swiat, Polozenie xy) {
	this->sila = 2;
	this->inicjatywa = 1;
	this->wiek = 0;
	this->swiat = swiat;
	this->xy = xy;
}

Zolw::Zolw(Swiat* swiat, Polozenie xy, int sila, int wiek) {
	this->sila = sila;
	this->inicjatywa = 1;
	this->wiek = wiek;
	this->swiat = swiat;
	this->xy = xy;
}

void Zolw::narodziny(int x1, int y1) {
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
		this->swiat->dodajOrganizm(new Zolw(this->swiat, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Zolw::akcja() {
	int czyRuch = rand() % 4;
	if (czyRuch != 0) return;
	int los;
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			los = rand() % 3;
			if (los == 0) ruch(0, 1);
			else if (los == 1) ruch(1, 1);
			else if (los == 2) ruch(1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			los = rand() % 3;
			if (los == 0) ruch(0, -1);
			else if (los == 1) ruch(1, -1);
			else if (los == 2) ruch(1, 0);
		}
		else {
			los = rand() % 5;
			if (los == 0) ruch(0, -1);
			else if (los == 1) ruch(1, -1);
			else if (los == 2) ruch(1, 0);
			else if (los == 3) ruch(0, 1);
			else if (los == 4) ruch(1, 1);
		}
	}
	else if (this->xy.x == this->swiat->getWysokosc() - 1) {
		if (this->xy.y == 0) {
			los = rand() % 3;
			if (los == 0) ruch(0, 1);
			else if (los == 1) ruch(-1, 1);
			else if (los == 2) ruch(-1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			los = rand() % 3;
			if (los == 0) ruch(0, -1);
			else if (los == 1) ruch(-1, -1);
			else if (los == 2) ruch(-1, 0);
		}
		else {
			los = rand() % 5;
			if (los == 0) ruch(0, 1);
			else if (los == 1) ruch(-1, 1);
			else if (los == 2) ruch(-1, 0);
			else if (los == 3) ruch(0, -1);
			else if (los == 4) ruch(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		los = rand() % 5;
		if (los == 0) ruch(0, 1);
		else if (los == 1) ruch(-1, 1);
		else if (los == 2) ruch(-1, 0);
		else if (los == 3) ruch(1, 1);
		else if (los == 4) ruch(1, 0);
	}
	else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
		los = rand() % 5;
		if (los == 0) ruch(0, -1);
		else if (los == 1) ruch(-1, -1);
		else if (los == 2) ruch(-1, 0);
		else if (los == 3) ruch(1, -1);
		else if (los == 4) ruch(1, 0);
	}
	else {
		los = rand() % 8;
		if (los == 0) ruch(0, 1);
		else if (los == 1) ruch(1, 0);
		else if (los == 2) ruch(1, 1);
		else if (los == 3) ruch(-1, 0);
		else if (los == 4) ruch(-1, 1);
		else if (los == 5) ruch(-1, -1);
		else if (los == 6) ruch(0, -1);
		else if (los == 7) ruch(1, -1);
	}
}

void Zolw::kolizja(Organizm* org) {
	if (dynamic_cast<Zolw*>(org)) {
		if (this->wiek > 2) rozmnazanie();
	}
	else if (org->getSila() < 5) {
		string komentarz = "";
		komentarz += this->getNazwa();
		komentarz += this->getXY();
		komentarz += " zatrzymal: ";
		komentarz += org->getNazwa();
		komentarz += org->getXY();
		swiat->dziennik(komentarz);
		return;
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

void Zolw::rysowanie() {
	cout << 'Z';
}

string Zolw::getNazwa() {
	return "Zolw";
}

Zolw::~Zolw() {

}