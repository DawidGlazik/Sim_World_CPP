#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	virtual void sprawdzIZasiej(int x1, int y1);
public:
	Roslina();
	Roslina(Swiat* swiat, Polozenie xy);
	void akcja() override;
	void kolizja(Organizm* org) override;
	void rysowanie() override;
	string getNazwa() override;
	~Roslina();
};