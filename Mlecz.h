#pragma once
#include "Roslina.h"

class Mlecz :public Roslina {
protected:
	void sprawdzIZasiej(int x1, int y1) override;
public:
	Mlecz();
	Mlecz(Swiat* swiat, Polozenie xy);
	Mlecz(Swiat* swiat, Polozenie xy, int wiek);
	void rysowanie() override;
	void akcja() override;
	string getNazwa() override;
	~Mlecz();
};