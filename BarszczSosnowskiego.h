#pragma once
#include "Roslina.h"

class BarszczSosnowskiego :public Roslina {
private:
	void sprawdzIZabij(int x1, int y1);
	void zabijOkolice();
protected:
	void sprawdzIZasiej(int x1, int y1) override;
public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(Swiat* swiat, Polozenie xy);
	BarszczSosnowskiego(Swiat* swiat, Polozenie xy, int wiek);
	void rysowanie() override;
	void akcja() override;
	void kolizja(Organizm* org);
	string getNazwa() override;
	~BarszczSosnowskiego();
};