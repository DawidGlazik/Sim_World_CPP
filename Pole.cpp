#include "Pole.h"

Pole::Pole() {
	this->sila = 0;
	this->wiek = 0;
}

Pole::Pole(Swiat* swiat, Polozenie xy) {
	this->swiat = swiat;
	this->xy = xy;
	this->sila = 0;
	this->wiek = 0;
}

void Pole::rysowanie() {
	cout << ' ';
}

Pole::~Pole() {

}