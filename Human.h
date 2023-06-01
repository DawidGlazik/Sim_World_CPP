#pragma once
#include "Animal.h"

class Human : public Animal {
private:
	void checkAndKill(int x1, int y1);
	int lasting;
	int break_;
public:
	Human();
	Human(World* world, coords xy);
	Human(World* world, coords xy, int strength, int age, int lasting, int break_);
	void action(int direction);
	void print() override;
	string getName() override;
	void calopalenie();
	int getLasting();
	int getBreak_();
	void setLasting(int lasting);
	void addBreak_(int break_);
	~Human();
};