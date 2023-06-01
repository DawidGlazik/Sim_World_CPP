#pragma once
#include "Animal.h"

class Sheep : public Animal {
protected:
	void birth(int x1, int y1) override;
public:
	Sheep();
	Sheep(World* world, coords xy);
	Sheep(World* world, coords xy, int strength, int age);
	void print() override;
	string getName() override;
	~Sheep();
};