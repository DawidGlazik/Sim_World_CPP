#include "Sheep.h"
#include "Field.h"

Sheep::Sheep() {
	this->strength = 4;
	this->initiative = 4;
	this->age = 0;
}

Sheep::Sheep(World* world, coords xy) {
	this->strength = 4;
	this->initiative = 4;
	this->age = 0;
	this->world = world;
	this->xy = xy;
}

Sheep::Sheep(World* world, coords xy, int strength, int age) {
	this->strength = strength;
	this->initiative = 4;
	this->age = age;
	this->world = world;
	this->xy = xy;
}

void Sheep::birth(int x1, int y1) {
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
		this->world->addOrganism(new Sheep(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Sheep::print() {
	cout << 'S';
}

string Sheep::getName() {
	return "Sheep";
}

Sheep::~Sheep() {

}