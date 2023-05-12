#pragma once
#include "Roslina.h"

class Guarana :public Roslina {
protected:
	void sprawdzIZasiej(int x1, int y1) override;
public:
	Guarana();
	Guarana(Swiat* swiat, Polozenie xy);
	Guarana(Swiat* swiat, Polozenie xy, int wiek);
	void rysowanie() override;
	void kolizja(Organizm*) override;
	string getNazwa() override;
	~Guarana();
};