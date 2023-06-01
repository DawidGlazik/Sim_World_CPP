#pragma once
#include "Animal.h"

class Antelope : public Animal {
protected:
	void birth(int x1, int y1) override;
public:
	Antelope();
	Antelope(World* world, coords xy);
	Antelope(World* world, coords xy, int strength, int age);
	void action() override;
	void collision(Organism* org) override;
	void print() override;
	string getName() override;
	~Antelope();
};