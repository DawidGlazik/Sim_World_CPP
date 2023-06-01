#include "Animal.h"
#include "Field.h"
#include <vector>

Animal::Animal() {
	strength = 0;
	initiative = 0;
	xy = { 0,0 };
}

Animal::Animal(World *world, coords xy) {
	this->world = world;
	this->xy = xy;
}

void Animal::movement(int x1, int y1) {
	if (dynamic_cast<Field*>(this->world->board[this->xy.x + x1][this->xy.y + y1])) {
		this->world->board[this->xy.x + x1][this->xy.y + y1] = this->world->board[this->xy.x][this->xy.y];
		this->world->board[this->xy.x][this->xy.y] = new Field();
		this->xy.x += x1;
		this->xy.y += y1;
	}
	else {
		this->world->board[this->xy.x + x1][this->xy.y + y1]->collision(this);
	}
}

void Animal::birth(int x1, int y1) {
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
		this->world->addOrganism(new Animal(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Animal::reproduction() {
	int lot;
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			lot = rand() % 3;
			if (lot == 0) birth(0, 1);
			else if (lot == 1) birth(1, 1);
			else if (lot == 2) birth(1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			lot = rand() % 3;
			if (lot == 0) birth(0, -1);
			else if (lot == 1) birth(1, -1);
			else if (lot == 2) birth(1, 0);
		}
		else {
			lot = rand() % 5;
			if (lot == 0) birth(0, -1);
			else if (lot == 1) birth(1, -1);
			else if (lot == 2) birth(1, 0);
			else if (lot == 3) birth(0, 1);
			else if (lot == 4) birth(1, 1);
		}
	}
	else if (this->xy.x == this->world->getHeight() - 1) {
		if (this->xy.y == 0) {
			lot = rand() % 3;
			if (lot == 0) birth(0, 1);
			else if (lot == 1) birth(-1, 1);
			else if (lot == 2) birth(-1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			lot = rand() % 3;
			if (lot == 0) birth(0, -1);
			else if (lot == 1) birth(-1, -1);
			else if (lot == 2) birth(-1, 0);
		}
		else {
			lot = rand() % 5;
			if (lot == 0) birth(0, 1);
			else if (lot == 1) birth(-1, 1);
			else if (lot == 2) birth(-1, 0);
			else if (lot == 3) birth(0, -1);
			else if (lot == 4) birth(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		lot = rand() % 5;
		if (lot == 0) birth(0, 1);
		else if (lot == 1) birth(-1, 1);
		else if (lot == 2) birth(-1, 0);
		else if (lot == 3) birth(1, 1);
		else if (lot == 4) birth(1, 0);
	}
	else if (this->xy.y == this->world->getWidth() - 1) {
		lot = rand() % 5;
		if (lot == 0) birth(0, -1);
		else if (lot == 1) birth(-1, -1);
		else if (lot == 2) birth(-1, 0);
		else if (lot == 3) birth(1, -1);
		else if (lot == 4) birth(1, 0);
	}
	else {
		lot = rand() % 8;
		if (lot == 0) birth(0, 1);
		else if (lot == 1) birth(1, 0);
		else if (lot == 2) birth(1, 1);
		else if (lot == 3) birth(-1, 0);
		else if (lot == 4) birth(-1, 1);
		else if (lot == 5) birth(-1, -1);
		else if (lot == 6) birth(0, -1);
		else if (lot == 7) birth(1, -1);
	}
}

void Animal::action() {
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

void Animal::collision(Organism* org) {
	if (org->getName() == this->getName()) {
		if (this->age > 2) reproduction();
	}else if (org->getStrength() >= this->strength) {
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
	}else {
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

void Animal::print() {
	cout << 'An';
}

string Animal::getName() {
	return "Animal";
}

Animal::~Animal() {

}