#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
protected:
	void narodziny(int x1, int y1) override;
public:
	Zolw();
	Zolw(Swiat* swiat, Polozenie xy);
	Zolw(Swiat* swiat, Polozenie xy, int sila, int wiek);
	void akcja() override;
	void kolizja(Organizm* org) override;
	void rysowanie() override;
	string getNazwa() override;
	~Zolw();
};