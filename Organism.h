#pragma once
#include "World.h"

struct coords {
	int x;
	int y;
};

class World;

class Organism {
protected:
	int age;
	int strength;
	int initiative;
	coords xy;
public:
	World* world;
	Organism();
	Organism(World* world, int strength, int initiative, int age, coords xy);
	virtual void action();
	virtual void collision(Organism* org);
	virtual void print();
	virtual string getName();
	virtual string getXY();
	virtual int getAge();
	virtual int getStrength();
	virtual int getInitiative();
	virtual void addStrength(int strength);
	virtual void addAge(int age);
	void setX(int x);
	void setY(int y);
	virtual coords getCoords();
	~Organism();
};