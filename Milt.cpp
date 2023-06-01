#include "Milt.h"
#include "Field.h"

Milt::Milt() {
	this->strength = 0;
	this->age = 0;
}

Milt::Milt(World* world, coords xy) {
	this->world = world;
	this->xy = xy;
	this->strength = 0;
	this->age = 0;
}

Milt::Milt(World* world, coords xy, int age) {
	this->world = world;
	this->xy = xy;
	this->strength = 0;
	this->age = age;
}

void Milt::checkAndSeed(int x1, int y1) {
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
		this->world->addOrganism(new Milt(this->world, { this->xy.x + x1, this->xy.y + y1 }));
	}
}

void Milt::print() {
	cout << 'm';
}

void Milt::action() {
	for (int i = 0; i < 3; i++) {
		int lot1 = rand() % 15;
		int lot2;
		if (lot1 != 0) return;
		if (this->xy.x == 0) {
			lot2 = rand() % 11;
			if (this->xy.y == 0 && lot2 < 3) {
				if (lot2 == 0) checkAndSeed(0, 1);
				else if (lot2 == 1) checkAndSeed(1, 1);
				else if (lot2 == 2)checkAndSeed(1, 0);
			}
			else if (this->xy.y == this->world->getWidth() - 1 && lot2 < 6) {
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
			if (this->xy.y == 0 && lot2 < 3) {
				if (lot2 == 0) checkAndSeed(0, 1);
				else if (lot2 == 1) checkAndSeed(-1, 1);
				else if (lot2 == 2) checkAndSeed(-1, 0);
			}
			else if (this->xy.y == this->world->getWidth() - 1 && lot2 < 6) {
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
}

string Milt::getName() {
	return "Milt";
}

Milt::~Milt() {

}