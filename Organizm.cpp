#include "Organizm.h"
#include <string>
#include "Pole.h"

Organizm::Organizm() {
	this->sila = 0;
	this->inicjatywa = 0;
	this->xy = { 0,0 };
	this->wiek = 0;
}

Organizm::Organizm(Swiat* swiat, int sila, int inicjatywa, int wiek, Polozenie xy) {

}

void Organizm::akcja() {

}

string Organizm::getXY() {
	string tmp;
	tmp += "(";
	tmp += to_string(this->xy.x + 1);
	tmp += ",";
	tmp += to_string(this->xy.y + 1);
	tmp += ")";
	return tmp;
}

void Organizm::setX(int x) {
	this->xy.x = x;
}

void Organizm::setY(int y) {
	this->xy.y = y;
}

int Organizm::getWiek() {
	return this->wiek;
}

int Organizm::getSila() {
	return this->sila;
}

int Organizm::getInicjatywa() {
	return this->inicjatywa;
}

Polozenie Organizm::getPolozenie() {
	return this->xy;
}

void Organizm::addSila(int sila) {
	this->sila += sila;
}

void Organizm::addWiek(int wiek) {
	this->wiek += wiek;
}

void Organizm::kolizja(Organizm* org) {
	if (org->sila > this->sila) {
		string komentarz = "";
		komentarz += this->getNazwa();
		komentarz += " atakuje silniejszego: ";
		komentarz += org->getNazwa();
		komentarz += " i ginie.";
		swiat->dziennik(komentarz);
		swiat->plansza[this->xy.y][this->xy.x] = new Pole();
	}
}

void Organizm::rysowanie() {

}

string Organizm::getNazwa() {
	return "Organizm";
}

Organizm::~Organizm() {

}