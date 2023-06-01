#pragma once
#include "Organism.h"

class Animal : public Organism {
protected:
	virtual void movement(int x1, int y1);
	virtual void birth(int x1, int y1);
	void reproduction();
public:
	Animal();
	Animal(World* world, coords xy);
	void action() override;
	void collision(Organism* org) override;
	void print() override;
	string getName() override;
	~Animal();
};