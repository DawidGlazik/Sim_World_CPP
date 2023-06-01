#include "Antelope.h"
#include "Field.h"

Antelope::Antelope() {
	this->strength = 4;
	this->initiative = 4;
	this->age = 0;
}

Antelope::Antelope(World* world, coords xy) {
	this->strength = 4;
	this->initiative = 4;
	this->age = 0;
	this->world = world;
	this->xy = xy;
}

Antelope::Antelope(World* world, coords xy, int strength, int age) {
	this->strength = strength;
	this->initiative = 4;
	this->age = age;
	this->world = world;
	this->xy = xy;
}

void Antelope::birth(int x1, int y1) {
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
		this->world->addOrganism(new Antelope(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Antelope::action() {
	int lot;
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			lot = rand() % 5;
			if (lot == 0) movement(0, 1);
			else if (lot == 1) movement(1, 1);
			else if (lot == 2) movement(1, 0);
			else if (lot == 3) movement(0, 2);
			else if (lot == 4) movement(2, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			lot = rand() % 5;
			if (lot == 0) movement(0, -1);
			else if (lot == 1) movement(1, -1);
			else if (lot == 2) movement(1, 0);
			else if (lot == 3) movement(0, -2);
			else if (lot == 4) movement(2, 0);
		}
		else {
			lot = rand() % 8;
			if (lot == 0) movement(0, -1);
			else if (lot == 1) movement(1, -1);
			else if (lot == 2) movement(1, 0);
			else if (lot == 3) movement(0, 1);
			else if (lot == 4) movement(1, 1);
			else if (lot == 5 && this->xy.y != this->world->getWidth() - 2) movement(0, 2);
			else if (lot == 6 && this->xy.x != this->world->getHeight() - 2) movement(2, 0);
			else if (lot == 7 && this->xy.y != 1) movement(0, -2);
		}
	}
	else if (this->xy.x == this->world->getHeight() - 1) {
		if (this->xy.y == 0) {
			lot = rand() % 5;
			if (lot == 0) movement(0, 1);
			else if (lot == 1) movement(-1, 1);
			else if (lot == 2) movement(-1, 0);
			else if (lot == 3) movement(-2, 0);
			else if (lot == 4) movement(0, 2);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			lot = rand() % 5;
			if (lot == 0) movement(0, -1);
			else if (lot == 1) movement(-1, -1);
			else if (lot == 2) movement(-1, 0);
			else if (lot == 3) movement(-2, 0);
			else if (lot == 4) movement(0, -2);
		}
		else {
			lot = rand() % 8;
			if (lot == 0) movement(0, 1);
			else if (lot == 1) movement(-1, 1);
			else if (lot == 2) movement(-1, 0);
			else if (lot == 3) movement(0, -1);
			else if (lot == 4) movement(-1, -1);
			else if (lot == 5 && this->xy.y != this->world->getWidth() - 2) movement(0, 2);
			else if (lot == 6 && this->xy.x != 1) movement(-2, 0);
			else if (lot == 7 && this->xy.y != 1) movement(0, -2);
		}
	}
	else if (this->xy.y == 0) {
		lot = rand() % 8;
		if (lot == 0) movement(0, 1);
		else if (lot == 1) movement(-1, 1);
		else if (lot == 2) movement(-1, 0);
		else if (lot == 3) movement(1, 1);
		else if (lot == 4) movement(1, 0);
		else if (lot == 5) movement(0, 2);
		else if (lot == 6 && this->xy.x != 1) movement(-2, 0);
		else if (lot == 7 && this->xy.x != this->world->getHeight() - 2) movement(2, 0);
	}
	else if (this->xy.y == this->world->getWidth() - 1) {
		lot = rand() % 8;
		if (lot == 0) movement(0, -1);
		else if (lot == 1) movement(-1, -1);
		else if (lot == 2) movement(-1, 0);
		else if (lot == 3) movement(1, -1);
		else if (lot == 4) movement(1, 0);
		else if (lot == 5) movement(0, -2);
		else if (lot == 6 && this->xy.x != 1) movement(-2, 0);
		else if (lot == 7 && this->xy.x != this->world->getHeight() - 2) movement(2, 0);
	}
	else {
		lot = rand() % 12;
		if (lot == 0) movement(0, 1);
		else if (lot == 1) movement(1, 0);
		else if (lot == 2) movement(1, 1);
		else if (lot == 3) movement(-1, 0);
		else if (lot == 4) movement(-1, 1);
		else if (lot == 5) movement(-1, -1);
		else if (lot == 6) movement(0, -1);
		else if (lot == 7) movement(1, -1);
		else if (lot == 8 && this->xy.x != 1) movement(-2, 0);
		else if (lot == 9 && this->xy.x != this->world->getHeight() - 2) movement(2, 0);
		else if (lot == 10 && this->xy.y != this->world->getWidth() - 2) movement(0, 2);
		else if (lot == 11 && this->xy.y != 1) movement(0, -2);
	}
}

void Antelope::collision(Organism* org) {
	int chance = rand() % 2;
	if (dynamic_cast<Antelope*>(org)) {
		if (this->age > 2) reproduction();
	}
	else if (chance == 0) {
		string comment = "";
		comment += this->getName();
		comment += this->getXY();
		comment += " flees.";
		this->world->log(comment);
		if (this->xy.y != world->getWidth() - 1 && dynamic_cast<Field*>(this->world->board[this->xy.x][this->xy.y + 1])) {
			world->board[this->xy.x][this->xy.y + 1] = world->board[this->xy.x][this->xy.y];
			world->board[this->xy.x][this->xy.y] = new Field();
			this->xy.y++;
		}
		else if (this->xy.x != world->getHeight() - 1 && dynamic_cast<Field*>(this->world->board[this->xy.x + 1][this->xy.y])) {
			world->board[this->xy.x + 1][this->xy.y] = world->board[this->xy.x][this->xy.y];
			world->board[this->xy.x][this->xy.y] = new Field();
			this->xy.x++;
		}
		else if (this->xy.y != 0 && dynamic_cast<Field*>(this->world->board[this->xy.x][this->xy.y - 1])) {
			world->board[this->xy.x][this->xy.y - 1] = world->board[this->xy.x][this->xy.y];
			world->board[this->xy.x][this->xy.y] = new Field();
			this->xy.y--;
		}
		else if (this->xy.x != 0 && dynamic_cast<Field*>(this->world->board[this->xy.x - 1][this->xy.y])) {
			world->board[this->xy.x - 1][this->xy.y] = world->board[this->xy.x][this->xy.y];
			world->board[this->xy.x][this->xy.y] = new Field();
			this->xy.x--;
		}
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

void Antelope::print() {
	cout << 'A';
}

string Antelope::getName() {
	return "Antelope";
}

Antelope::~Antelope() {

}