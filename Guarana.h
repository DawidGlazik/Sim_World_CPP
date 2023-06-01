#pragma once
#include "Plant.h"

class Guarana :public Plant {
protected:
	void checkAndSeed(int x1, int y1) override;
public:
	Guarana();
	Guarana(World* world, coords xy);
	Guarana(World* world, coords xy, int age);
	void print() override;
	void collision(Organism*) override;
	string getName() override;
	~Guarana();
};