#pragma once
#include "Organism.h"

class Plant : public Organism {
protected:
	virtual void checkAndSeed(int x1, int y1);
public:
	Plant();
	Plant(World* world, coords xy);
	void action() override;
	void collision(Organism* org) override;
	void print() override;
	string getName() override;
	~Plant();
};