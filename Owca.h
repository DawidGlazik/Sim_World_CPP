#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
protected:
	void narodziny(int x1, int y1) override;
public:
	Owca();
	Owca(Swiat* swiat, Polozenie xy);
	Owca(Swiat* swiat, Polozenie xy, int sila, int wiek);
	void rysowanie() override;
	string getNazwa() override;
	~Owca();
};