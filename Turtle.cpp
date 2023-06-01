#include "Turtle.h"
#include "Field.h"

Turtle::Turtle() {
	this->strength = 2;
	this->initiative = 1;
	this->age = 0;
}

Turtle::Turtle(World* world, coords xy) {
	this->strength = 2;
	this->initiative = 1;
	this->age = 0;
	this->world = world;
	this->xy = xy;
}

Turtle::Turtle(World* world, coords xy, int strength, int age) {
	this->strength = strength;
	this->initiative = 1;
	this->age = age;
	this->world = world;
	this->xy = xy;
}

void Turtle::birth(int x1, int y1) {
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
		this->world->addOrganism(new Turtle(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Turtle::action() {
	int czymovement = rand() % 4;
	if (czymovement != 0) return;
	int lot;
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			lot = rand() % 3;
			if (lot == 0) movement(0, 1);
			else if (lot == 1) movement(1, 1);
			else if (lot == 2) movement(1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			lot = rand() % 3;
			if (lot == 0) movement(0, -1);
			else if (lot == 1) movement(1, -1);
			else if (lot == 2) movement(1, 0);
		}
		else {
			lot = rand() % 5;
			if (lot == 0) movement(0, -1);
			else if (lot == 1) movement(1, -1);
			else if (lot == 2) movement(1, 0);
			else if (lot == 3) movement(0, 1);
			else if (lot == 4) movement(1, 1);
		}
	}
	else if (this->xy.x == this->world->getHeight() - 1) {
		if (this->xy.y == 0) {
			lot = rand() % 3;
			if (lot == 0) movement(0, 1);
			else if (lot == 1) movement(-1, 1);
			else if (lot == 2) movement(-1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			lot = rand() % 3;
			if (lot == 0) movement(0, -1);
			else if (lot == 1) movement(-1, -1);
			else if (lot == 2) movement(-1, 0);
		}
		else {
			lot = rand() % 5;
			if (lot == 0) movement(0, 1);
			else if (lot == 1) movement(-1, 1);
			else if (lot == 2) movement(-1, 0);
			else if (lot == 3) movement(0, -1);
			else if (lot == 4) movement(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		lot = rand() % 5;
		if (lot == 0) movement(0, 1);
		else if (lot == 1) movement(-1, 1);
		else if (lot == 2) movement(-1, 0);
		else if (lot == 3) movement(1, 1);
		else if (lot == 4) movement(1, 0);
	}
	else if (this->xy.y == this->world->getWidth() - 1) {
		lot = rand() % 5;
		if (lot == 0) movement(0, -1);
		else if (lot == 1) movement(-1, -1);
		else if (lot == 2) movement(-1, 0);
		else if (lot == 3) movement(1, -1);
		else if (lot == 4) movement(1, 0);
	}
	else {
		lot = rand() % 8;
		if (lot == 0) movement(0, 1);
		else if (lot == 1) movement(1, 0);
		else if (lot == 2) movement(1, 1);
		else if (lot == 3) movement(-1, 0);
		else if (lot == 4) movement(-1, 1);
		else if (lot == 5) movement(-1, -1);
		else if (lot == 6) movement(0, -1);
		else if (lot == 7) movement(1, -1);
	}
}

void Turtle::collision(Organism* org) {
	if (dynamic_cast<Turtle*>(org)) {
		if (this->age > 2) reproduction();
	}
	else if (org->getStrength() < 5) {
		string comment = "";
		comment += this->getName();
		comment += this->getXY();
		comment += " stops: ";
		comment += org->getName();
		comment += org->getXY();
		world->log(comment);
		return;
	}
	else if (org->getStrength() > this->strength) {
		string comment = "";
		comment += org->getName();
		comment += org->getXY();
		comment += " defeats ";
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
	else {
		string comment = "";
		comment += org->getName();
		comment += org->getXY();
		comment += " beaten by ";
		comment += this->getName();
		comment += this->getXY();
		world->log(comment);
		world->board[org->getCoords().x][org->getCoords().y] = new Field();
		for (int i = 0; i < this->world->Organisms.size(); i++) {
			if (this->world->Organisms[i]->getCoords().x == org->getCoords().x && this->world->Organisms[i]->getCoords().y == org->getCoords().y) {
				this->world->Organisms.erase(this->world->Organisms.begin() + i);
			}
		}
	}
}

void Turtle::print() {
	cout << 'T';
}

string Turtle::getName() {
	return "Turtle";
}

Turtle::~Turtle() {

}