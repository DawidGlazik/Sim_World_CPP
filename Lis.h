#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
protected:
	void ruch(int x1, int y1) override;
	void narodziny(int x1, int y1) override;
public:
	Lis();
	Lis(Swiat* swiat, Polozenie xy);
	Lis(Swiat* swiat, Polozenie xy, int sila, int wiek);
	void rysowanie() override;
	string getNazwa() override;
	~Lis();
};