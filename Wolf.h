#pragma once
#include "Animal.h"

class Wolf : public Animal {
protected:
	void birth(int x1, int y1) override;
public:
	Wolf();
	Wolf(World* world, coords xy);
	Wolf(World* world, coords xy, int strength, int age);
	void print() override;
	string getName() override;
	~Wolf();
};