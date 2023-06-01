#pragma once
#include "Plant.h"

class Hogweed :public Plant {
private:
	void checkAndKill(int x1, int y1);
	void killArea();
protected:
	void checkAndSeed(int x1, int y1) override;
public:
	Hogweed();
	Hogweed(World* world, coords xy);
	Hogweed(World* world, coords xy, int age);
	void print() override;
	void action() override;
	void collision(Organism* org);
	string getName() override;
	~Hogweed();
};