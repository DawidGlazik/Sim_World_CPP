#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	virtual void ruch(int x1, int y1);
	virtual void narodziny(int x1, int y1);
	void rozmnazanie();
public:
	Zwierze();
	Zwierze(Swiat* swiat, Polozenie xy);
	void akcja() override;
	void kolizja(Organizm* org) override;
	void rysowanie() override;
	string getNazwa() override;
	~Zwierze();
};