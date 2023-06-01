#include "Field.h"

Field::Field() {
	this->strength = 0;
	this->age = 0;
}

Field::Field(World* world, coords xy) {
	this->world = world;
	this->xy = xy;
	this->strength = 0;
	this->age = 0;
}

void Field::print() {
	cout << ' ';
}

Field::~Field() {

}