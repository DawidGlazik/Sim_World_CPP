#pragma once
#include "Roslina.h"

class Pole : public Roslina {
public:
	Pole();
	Pole(Swiat* swiat, Polozenie xy);
	void rysowanie() override;
	~Pole();
};
