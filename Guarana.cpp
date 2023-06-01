#include "Guarana.h"
#include "Field.h"

Guarana::Guarana() {
	this->strength = 0;
	this->age = 0;
}

Guarana::Guarana(World* world, coords xy) {
	this->world = world;
	this->xy = xy;
	this->strength = 0;
	this->age = 0;
}

Guarana::Guarana(World* world, coords xy, int age) {
	this->world = world;
	this->xy = xy;
	this->strength = 0;
	this->age = age;
}

void Guarana::print() {
	cout << 'g';
}

void Guarana::checkAndSeed(int x1, int y1) {
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
		this->world->addOrganism(new Guarana(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Guarana::collision(Organism* org) {
	string comment = "";
	comment += org->getName();
	comment += org->getXY();
	comment += " - strength + 3 ";
	comment += this->getName();
	comment += this->getXY();
	org->addStrength(3);
	world->log(comment);
	for (int i = 0; i < this->world->Organisms.size(); i++) {
		if (this->world->Organisms[i]->getCoords().x == this->xy.x && this->world->Organisms[i]->getCoords().y == this->xy.y) {
			this->world->Organisms.erase(this->world->Organisms.begin() + i);
		}
	}
	world->board[this->xy.x][this->xy.y] = org;
	world->board[org->getCoords().x][org->getCoords().y] = new Field();
	org->setX(this->xy.x);
	org->setY(this->xy.y);
}

string Guarana::getName() {
	return "Guarana";
}

Guarana::~Guarana() {

}