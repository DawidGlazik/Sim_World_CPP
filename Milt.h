#pragma once
#include "Plant.h"

class Milt :public Plant {
protected:
	void checkAndSeed(int x1, int y1) override;
public:
	Milt();
	Milt(World* world, coords xy);
	Milt(World* world, coords xy, int age);
	void print() override;
	void action() override;
	string getName() override;
	~Milt();
};