#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
protected:
	void narodziny(int x1, int y1) override;
public:
	Wilk();
	Wilk(Swiat* swiat, Polozenie xy);
	Wilk(Swiat* swiat, Polozenie xy, int sila, int wiek);
	void rysowanie() override;
	string getNazwa() override;
	~Wilk();
};