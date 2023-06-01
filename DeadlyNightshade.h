#pragma once
#include "Plant.h"

class DeadlyNightshade :public Plant {
protected:
	void checkAndSeed(int x1, int y1) override;
public:
	DeadlyNightshade();
	DeadlyNightshade(World* world, coords xy);
	DeadlyNightshade(World* world, coords xy, int age);
	void print() override;
	void collision(Organism* org) override;
	string getName() override;
	~DeadlyNightshade();
};