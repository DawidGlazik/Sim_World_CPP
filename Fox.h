#pragma once
#include "Animal.h"

class Fox : public Animal {
protected:
	void movement(int x1, int y1) override;
	void birth(int x1, int y1) override;
public:
	Fox();
	Fox(World* world, coords xy);
	Fox(World* world, coords xy, int strength, int age);
	void print() override;
	string getName() override;
	~Fox();
};