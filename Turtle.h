#pragma once
#include "Animal.h"

class Turtle : public Animal {
protected:
	void birth(int x1, int y1) override;
public:
	Turtle();
	Turtle(World* world, coords xy);
	Turtle(World* world, coords xy, int strength, int age);
	void action() override;
	void collision(Organism* org) override;
	void print() override;
	string getName() override;
	~Turtle();
};