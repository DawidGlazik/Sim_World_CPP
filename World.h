#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Organism.h"
using namespace std;

class Organism;

class World {
private:
	int turn;
	int width;
	int height;
	string console;
public:
	vector <Organism*> Organisms;
	Organism*** board;
	World();
	World(int width, int height);
	void save();
	void load();
	void handleTurn(int direction);
	void printWorld();
	void addOrganism(Organism* new_);
	void log(string console);
	void printOrganisms();
	int getWidth();
	int getHeight();
	void startCalopalenie();
	~World();
};