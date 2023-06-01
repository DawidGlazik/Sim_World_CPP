#include "Plant.h"
#include "Field.h"

Plant::Plant() {
	this->strength = 0;
	this->initiative = 0;
	this->xy = { 0,0 };
}

Plant::Plant(World* world, coords xy) {
	this->strength = 0;
	this->initiative = 0;
	this->world = world;
	this->xy = xy;
}

void Plant::checkAndSeed(int x1, int y1) {
	string comment;
	if (dynamic_cast<Field*>(this->world->board[this->xy.x + x1][this->xy.y + y1])) {
		comment = "";
		comment += "Seed plant";
		comment += "(";
		comment += to_string(this->xy.x + x1 + 1);
		comment += ",";
		comment += to_string(this->xy.y + + y1 + 1);
		comment += ")";
		this->world->log(comment);
		this->world->addOrganism(new Plant(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Plant::action() {
	int lot1 = rand() % 15;
	int lot2;
	if (lot1 != 0) return;
	if (this->xy.x == 0) {
		lot2 = rand() % 11;
		if (this->xy.y == 0) {
			if (lot2 == 0) checkAndSeed(0, 1);
			else if (lot2 == 1) checkAndSeed(1, 1);
			else if (lot2 == 2)checkAndSeed(1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			if (lot2 == 3) checkAndSeed(0, -1);
			else if (lot2 == 4) checkAndSeed(1, -1);
			else if (lot2 == 5) checkAndSeed(1, 0);
		}
		else {
			if (lot2 == 6) checkAndSeed(0, -1);
			else if (lot2 == 7) checkAndSeed(1, -1);
			else if (lot2 == 8) checkAndSeed(1, 0);
			else if (lot2 == 9) checkAndSeed(0, 1);
			else if (lot2 == 10) checkAndSeed(1, 1);
		}
	}
	else if (this->xy.x == this->world->getHeight() - 1) {
		lot2 = rand() % 11;
		if (this->xy.y == 0) {
			if (lot2 == 0) checkAndSeed(0, 1);
			else if (lot2 == 1) checkAndSeed(-1, 1);
			else if (lot2 == 2) checkAndSeed(-1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			if (lot2 == 3) checkAndSeed(0, -1);
			else if (lot2 == 4) checkAndSeed(-1, -1);
			else if (lot2 == 5) checkAndSeed(-1, 0);
		}
		else {
			if (lot2 == 6) checkAndSeed(0, 1);
			else if (lot2 == 7) checkAndSeed(-1, 1);
			else if (lot2 == 8) checkAndSeed(-1, 0);
			else if (lot2 == 9) checkAndSeed(0, -1);
			else if (lot2 == 10) checkAndSeed(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		lot2 = rand() % 5;
		if (lot2 == 0) checkAndSeed(0, 1);
		else if (lot2 == 1) checkAndSeed(-1, 1);
		else if (lot2 == 2) checkAndSeed(-1, 0);
		else if (lot2 == 3) checkAndSeed(1, 1);
		else if (lot2 == 4) checkAndSeed(1, 0);
	}
	else if (this->xy.y == this->world->getWidth() - 1) {
		lot2 = rand() % 5;
		if (lot2 == 0) checkAndSeed(0, -1);
		else if (lot2 == 1) checkAndSeed(-1, -1);
		else if (lot2 == 2) checkAndSeed(-1, 0);
		else if (lot2 == 3) checkAndSeed(1, -1);
		else if (lot2 == 4) checkAndSeed(1, 0);
	}
	else {
		lot2 = rand() % 8;
		if (lot2 == 0) checkAndSeed(0, 1);
		else if (lot2 == 1) checkAndSeed(1, 0);
		else if (lot2 == 2) checkAndSeed(1, 1);
		else if (lot2 == 3) checkAndSeed(-1, 0);
		else if (lot2 == 4) checkAndSeed(-1, 1);
		else if (lot2 == 5) checkAndSeed(-1, -1);
		else if (lot2 == 6) checkAndSeed(0, -1);
		else if (lot2 == 7) checkAndSeed(1, -1);
	}
}

void Plant::collision(Organism* org) {
	string comment = "";
	comment += org->getName();
	comment += org->getXY();
	comment += " eats ";
	comment += this->getName();
	comment += this->getXY();
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

void Plant::print() {
	cout << 'p';
}

string Plant::getName() {
	return "Plant";
}

Plant::~Plant() {

}