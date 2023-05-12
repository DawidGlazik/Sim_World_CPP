#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	void sprawdzIZabij(int x1, int y1);
	int trwanie;
	int przerwa;
public:
	Czlowiek();
	Czlowiek(Swiat* swiat, Polozenie xy);
	Czlowiek(Swiat* swiat, Polozenie xy, int sila, int wiek, int trwanie, int przerwa);
	void akcja(int kierunek);
	void rysowanie() override;
	string getNazwa() override;
	void calopalenie();
	int getTrwanie();
	int getPrzerwa();
	void setTrwanie(int trwanie);
	void addPrzerwa(int przerwa);
	~Czlowiek();
};