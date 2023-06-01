#include "Hogweed.h"
#include "Field.h"
#include "Animal.h"

Hogweed::Hogweed() {
	this->strength = 10;
	this->age = 0;
}

Hogweed::Hogweed(World* world, coords xy) {
	this->world = world;
	this->xy = xy;
	this->strength = 10;
	this->age = 0;
}

Hogweed::Hogweed(World* world, coords xy, int age) {
	this->world = world;
	this->xy = xy;
	this->strength = 10;
	this->age = age;
}

void Hogweed::checkAndSeed(int x1, int y1) {
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
		this->world->addOrganism(new Hogweed(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Hogweed::checkAndKill(int x1, int y1) {
	string comment;
	if (dynamic_cast<Animal*>(this->world->board[this->xy.x + x1][this->xy.y + y1])) {
		comment = "";
		comment += this->world->board[this->xy.x + x1][this->xy.y + y1]->getName();
		comment += this->world->board[this->xy.x + x1][this->xy.y + y1]->getXY();
		comment += " killed by ";
		comment += this->getName();
		comment += this->getXY();
		this->world->log(comment);
		this->world->board[this->xy.x + x1][this->xy.y + y1] = new Field();
		for (int i = 0; i < this->world->Organisms.size(); i++) {
			if (this->world->Organisms[i]->getCoords().x == this->xy.x + x1 && this->world->Organisms[i]->getCoords().y == this->xy.y + y1) {
				this->world->Organisms.erase(this->world->Organisms.begin() + i);
			}
		}
	}
}

void Hogweed::print() {
	cout << 'h';
}

void Hogweed::killArea() {
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			checkAndKill(0, 1);
			checkAndKill(1, 1);
			checkAndKill(1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			checkAndKill(0, -1);
			checkAndKill(1, -1);
			checkAndKill(1, 0);
		}
		else {
			checkAndKill(0, -1);
			checkAndKill(1, -1);
			checkAndKill(1, 0);
			checkAndKill(0, 1);
			checkAndKill(1, 1);
		}
	}
	else if (this->xy.x == this->world->getHeight() - 1) {
		if (this->xy.y == 0) {
			checkAndKill(0, 1);
			checkAndKill(-1, 1);
			checkAndKill(-1, 0);
		}
		else if (this->xy.y == this->world->getWidth() - 1) {
			checkAndKill(0, -1);
			checkAndKill(-1, -1);
			checkAndKill(-1, 0);
		}
		else {
			checkAndKill(0, 1);
			checkAndKill(-1, 1);
			checkAndKill(-1, 0);
			checkAndKill(0, -1);
			checkAndKill(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		checkAndKill(0, 1);
		checkAndKill(-1, 1);
		checkAndKill(-1, 0);
		checkAndKill(1, 1);
		checkAndKill(1, 0);
	}
	else if (this->xy.y == this->world->getWidth() - 1) {
		checkAndKill(0, -1);
		checkAndKill(-1, -1);
		checkAndKill(-1, 0);
		checkAndKill(1, -1);
		checkAndKill(1, 0);
	}
	else {
		checkAndKill(0, 1);
		checkAndKill(1, 0);
		checkAndKill(1, 1);
		checkAndKill(-1, 0);
		checkAndKill(-1, 1);
		checkAndKill(-1, -1);
		checkAndKill(0, -1);
		checkAndKill(1, -1);
	}
}

void Hogweed::action() {
	killArea();
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

void Hogweed::collision(Organism* org) {
	string comment = "";
	comment += org->getName();
	comment += " eats ";
	comment += this->getName();
	comment += " and dies";
	world->log(comment);
	world->board[this->xy.x][this->xy.y] = new Field();
	world->board[org->getCoords().y][org->getCoords().x] = new Field();
}

string Hogweed::getName() {
	return "Hogweed";
}

Hogweed::~Hogweed() {
	
}