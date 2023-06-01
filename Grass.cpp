#include "Grass.h"
#include "Field.h"

Grass::Grass() {
	this->strength = 0;
	this->age = 0;
}

Grass::Grass(World* world, coords xy) {
	this->world = world;
	this->xy = xy;
	this->strength = 0;
	this->age = 0;
}

Grass::Grass(World* world, coords xy, int age) {
	this->world = world;
	this->xy = xy;
	this->strength = 0;
	this->age = age;
}

void Grass::checkAndSeed(int x1, int y1) {
	string comment;
	if (dynamic_cast<Field*>(this->world->board[this->xy.x + x1][this->xy.y + y1])) {
		comment = "";
		comment += "Seed ";
		comment += this->getName();
		comment += "(";
		comment += to_string(this->xy.x + x1 + 1);
		comment += ",";
		comment += to_string(this->xy.y + +y1 + 1);
		comment += ")";
		this->world->log(comment);
		this->world->addOrganism(new Grass(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Grass::print() {
	cout << 't';
}

string Grass::getName() {
	return "Grass";
}

Grass::~Grass() {

}