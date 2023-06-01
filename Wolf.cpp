#include "Wolf.h"
#include "Field.h"

Wolf::Wolf() {
	this->strength = 9;
	this->initiative = 5;
	this->age = 0;
}

Wolf::Wolf(World* world, coords xy) {
	this->strength = 9;
	this->initiative = 5;
	this->age = 0;
	this->world = world;
	this->xy = xy;
}

Wolf::Wolf(World* world, coords xy, int strength, int age) {
	this->strength = strength;
	this->initiative = 5;
	this->age = age;
	this->world = world;
	this->xy = xy;
}

void Wolf::birth(int x1, int y1) {
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
		this->world->addOrganism(new Wolf(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Wolf::print() {
	cout << 'W';
}

string Wolf::getName() {
	return "Wolf";
}

Wolf::~Wolf() {

}