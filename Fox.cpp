#include "Fox.h"
#include "Field.h"

Fox::Fox() {
	this->strength = 3;
	this->initiative = 7;
	this->age = 0;
}

Fox::Fox(World* world, coords xy) {
	this->strength = 3;
	this->initiative = 7;
	this->age = 0;
	this->world = world;
	this->xy = xy;
}

Fox::Fox(World* world, coords xy, int strength, int age) {
	this->strength = strength;
	this->initiative = 7;
	this->age = age;
	this->world = world;
	this->xy = xy;
}

void Fox::movement(int x1, int y1){
	if (dynamic_cast<Field*>(this->world->board[this->xy.x + x1][this->xy.y + y1])) {
		this->world->board[this->xy.x + x1][this->xy.y + y1] = this->world->board[this->xy.x][this->xy.y];
		this->world->board[this->xy.x][this->xy.y] = new Field();
		this->xy.x += x1;
		this->xy.y += y1;
	}
	else {
		if (this->world->board[this->xy.x + x1][this->xy.y + y1]->getStrength() > this->getStrength()) return;
		else this->world->board[this->xy.x + x1][this->xy.y + y1]->collision(this);
	}
}

void Fox::birth(int x1, int y1) {
	if (dynamic_cast<Field*>(this->world->board[this->xy.x + x1][this->xy.y + y1])) {
		string comment = "";
		comment += "New birth: ";
		comment += this->getName();
		comment += "(";
		comment += to_string(this->xy.x + x1 + 1);
		comment += ",";
		comment += to_string(this->xy.y + y1 + 1);
		comment += ")";
		this->world->log(comment);
		this->world->addOrganism(new Fox(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Fox::print() {
	cout << 'F';
}

string Fox::getName() {
	return "Fox";
}

Fox::~Fox() {

}