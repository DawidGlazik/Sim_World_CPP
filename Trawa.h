#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
protected:
	void sprawdzIZasiej(int x1, int y1) override;
public:
	Trawa();
	Trawa(Swiat* swiat, Polozenie xy);
	Trawa(Swiat* swiat, Polozenie xy, int wiek);
	void rysowanie() override;
	string getNazwa() override;
	~Trawa();
};
