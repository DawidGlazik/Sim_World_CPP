#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
protected:
	void narodziny(int x1, int y1) override;
public:
	Antylopa();
	Antylopa(Swiat* swiat, Polozenie xy);
	Antylopa(Swiat* swiat, Polozenie xy, int sila, int wiek);
	void akcja() override;
	void kolizja(Organizm* org) override;
	void rysowanie() override;
	string getNazwa() override;
	~Antylopa();
};