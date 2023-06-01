#include "DeadlyNightshade.h"
#include "Field.h"

DeadlyNightshade::DeadlyNightshade() {
	this->strength = 99;
	this->age = 0;
}

DeadlyNightshade::DeadlyNightshade(World* world, coords xy) {
	this->world = world;
	this->xy = xy;
	this->strength = 99;
	this->age = 0;
}

DeadlyNightshade::DeadlyNightshade(World* world, coords xy, int age) {
	this->world = world;
	this->xy = xy;
	this->strength = 99;
	this->age = age;
}

void DeadlyNightshade::print() {
	cout << 'd';
}

void DeadlyNightshade::checkAndSeed(int x1, int y1) {
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
		this->world->addOrganism(new DeadlyNightshade(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void DeadlyNightshade::collision(Organism* org) {
	string comment = "";
	comment += org->getName();
	comment += org->getXY();
	comment += " eats ";
	comment += this->getName();
	comment += this->getXY();
	comment += " and dies";
	world->log(comment);
	world->board[this->xy.x][this->xy.y] = new Field();
	world->board[org->getCoords().x][org->getCoords().y] = new Field();
	for (int i = 0; i < this->world->Organisms.size(); i++) {
		if (this->world->Organisms[i]->getCoords().x == this->xy.x && this->world->Organisms[i]->getCoords().y == this->xy.y) {
			this->world->Organisms.erase(this->world->Organisms.begin() + i);
		}
		if (this->world->Organisms[i]->getCoords().x == org->getCoords().x && this->world->Organisms[i]->getCoords().y == org->getCoords().y) {
			this->world->Organisms.erase(this->world->Organisms.begin() + i);
		}
	}
}

string DeadlyNightshade::getName() {
	return "Deadly_Nightshade";
}

DeadlyNightshade::~DeadlyNightshade() {

}