#include "Organism.h"
#include <string>
#include "Field.h"

Organism::Organism() {
	this->strength = 0;
	this->initiative = 0;
	this->xy = { 0,0 };
	this->age = 0;
}

Organism::Organism(World* world, int strength, int initiative, int age, coords xy) {

}

void Organism::action() {

}

string Organism::getXY() {
	string tmp;
	tmp += "(";
	tmp += to_string(this->xy.x + 1);
	tmp += ",";
	tmp += to_string(this->xy.y + 1);
	tmp += ")";
	return tmp;
}

void Organism::setX(int x) {
	this->xy.x = x;
}

void Organism::setY(int y) {
	this->xy.y = y;
}

int Organism::getAge() {
	return this->age;
}

int Organism::getStrength() {
	return this->strength;
}

int Organism::getInitiative() {
	return this->initiative;
}

coords Organism::getCoords() {
	return this->xy;
}

void Organism::addStrength(int strength) {
	this->strength += strength;
}

void Organism::addAge(int age) {
	this->age += age;
}

void Organism::collision(Organism* org) {
	if (org->strength > this->strength) {
		string comment = "";
		comment += this->getName();
		comment += " attacks stronger: ";
		comment += org->getName();
		comment += " and dies.";
		world->log(comment);
		world->board[this->xy.y][this->xy.x] = new Field();
	}
}

void Organism::print() {

}

string Organism::getName() {
	return "Organism";
}

Organism::~Organism() {

}