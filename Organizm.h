#pragma once
#include "Swiat.h"
struct Polozenie {
	int x;
	int y;
};

class Swiat;

class Organizm {
protected:
	int wiek;
	int sila;
	int inicjatywa;
	Polozenie xy;
public:
	Swiat* swiat;
	Organizm();
	Organizm(Swiat* swiat, int sila, int inicjatywa, int wiek, Polozenie xy);
	virtual void akcja();
	virtual void kolizja(Organizm* org);
	virtual void rysowanie();
	virtual string getNazwa();
	virtual string getXY();
	virtual int getWiek();
	virtual int getSila();
	virtual int getInicjatywa();
	virtual void addSila(int sila);
	virtual void addWiek(int wiek);
	void setX(int x);
	void setY(int y);
	virtual Polozenie getPolozenie();
	~Organizm();
};