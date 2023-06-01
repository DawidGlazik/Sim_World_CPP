#pragma once
#include "Plant.h"

class Grass : public Plant {
protected:
	void checkAndSeed(int x1, int y1) override;
public:
	Grass();
	Grass(World* world, coords xy);
	Grass(World* world, coords xy, int age);
	void print() override;
	string getName() override;
	~Grass();
};
