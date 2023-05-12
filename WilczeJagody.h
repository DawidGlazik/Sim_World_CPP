#pragma once
#include "Roslina.h"

class WilczeJagody :public Roslina {
protected:
	void sprawdzIZasiej(int x1, int y1) override;
public:
	WilczeJagody();
	WilczeJagody(Swiat* swiat, Polozenie xy);
	WilczeJagody(Swiat* swiat, Polozenie xy, int wiek);
	void rysowanie() override;
	void kolizja(Organizm* org) override;
	string getNazwa() override;
	~WilczeJagody();
};