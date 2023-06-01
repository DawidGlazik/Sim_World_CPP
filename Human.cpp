#include "Human.h"
#include "Field.h"

Human::Human() {
	this->strength = 5;
	this->initiative = 4;
	this->age = 0;
	this->lasting = 5;
	this->break_ = 0;
}

Human::Human(World* world, coords xy) {
	this->strength = 5;
	this->initiative = 4;
	this->age = 0;
	this->world = world;
	this->xy = xy;
	this->lasting = 5;
	this->break_ = 0;
}

Human::Human(World* world, coords xy, int strength, int age, int lasting, int break_) {
	this->strength = strength;
	this->initiative = 4;
	this->age = age;
	this->world = world;
	this->xy = xy;
	this->lasting = lasting;
	this->break_ = break_;
}

void Human::checkAndKill(int x1, int y1) {
	string comment;
	if (!dynamic_cast<Field*>(this->world->board[this->xy.x + x1][this->xy.y + y1])) {
		comment = "";
		comment += this->world->board[this->xy.x + x1][this->xy.y + y1]->getName();
		comment += this->world->board[this->xy.x + x1][this->xy.y + y1]->getXY();
		comment += " killed by (calopalenie) ";
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

void Human::action(int direction) {
	if (direction == 0) return;
	else if (direction == 1) {
		if (this->xy.x == 0) return;
		else {
			if (dynamic_cast<Field*>(this->world->board[this->xy.x - 1][this->xy.y])) {
				this->world->board[this->xy.x - 1][this->xy.y] = this->world->board[this->xy.x][this->xy.y];
				this->world->board[this->xy.x][this->xy.y] = new Field();
				this->xy.x--;
			}
			else {
				this->world->board[this->xy.x - 1][this->xy.y]->collision(this);
			}
		}
	}
	else if (direction == 2) {
		if (this->xy.x == this->world->getHeight() - 1) return;
		else {
			if (dynamic_cast<Field*>(this->world->board[this->xy.x + 1][this->xy.y])) {
				this->world->board[this->xy.x + 1][this->xy.y] = this->world->board[this->xy.x][this->xy.y];
				this->world->board[this->xy.x][this->xy.y] = new Field();
				this->xy.x++;
			}
			else {
				this->world->board[this->xy.x + 1][this->xy.y]->collision(this);
			}
		}
	}
	else if (direction == 3) {
		if (this->xy.y == 0) return;
		else {
			if (dynamic_cast<Field*>(this->world->board[this->xy.x][this->xy.y - 1])) {
				this->world->board[this->xy.x][this->xy.y - 1] = this->world->board[this->xy.x][this->xy.y];
				this->world->board[this->xy.x][this->xy.y] = new Field();
				this->xy.y--;
			}
			else {
				this->world->board[this->xy.x][this->xy.y - 1]->collision(this);
			}
		}
	}
	else if (direction == 4) {
		if (this->xy.y == this->world->getWidth() - 1) return;
		else {
			if (dynamic_cast<Field*>(this->world->board[this->xy.x][this->xy.y + 1])) {
				this->world->board[this->xy.x][this->xy.y + 1] = this->world->board[this->xy.x][this->xy.y];
				this->world->board[this->xy.x][this->xy.y] = new Field();
				this->xy.y++;
			}
			else {
				this->world->board[this->xy.x][this->xy.y + 1]->collision(this);
			}
		}
	}
}

void Human::print() {
	cout << 'H';
}

string Human::getName() {
	return "Human";
}

int Human::getLasting() {
	return this->lasting;
}

int Human::getBreak_() {
	return this->break_;
}

void Human::setLasting(int lasting) {
	this->lasting = lasting;
}

void Human::addBreak_(int break_) {
	this->break_ += break_;
}

void Human::calopalenie() {
	this->lasting--;
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

Human::~Human() {

}