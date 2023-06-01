#include "Organism.h"
#include <iostream>
using namespace std;
#include <Windows.h>
#include "Organisms.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>

World::World() {
	this->turn = 0;
	this->console = "";
}

World::World(const int width, const int height) {
	this->turn = 0;
	this->width = width;
	this->height = height;
	this->console = "";
	this->Organisms.reserve(width * height);
	board = new Organism** [height];
	for (int i = 0; i < height; i++) {
		board[i] = new Organism * [width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) board[i][j] = new Field(this, {j, i});
	}

	srand(time(NULL));
	int random1, random2, random3, numberOfOrganisms, k;
	numberOfOrganisms = width * height / 15;
	Human* human = new Human(this, { height / 2, width / 2 });
	addOrganism(human);
	for (int i = 0; i < numberOfOrganisms; i++) {
		random1 = rand() % height;
		random2 = rand() % width;
		random3 = rand() % 1000;
		if (dynamic_cast<Field*>(board[random1][random2])) {
			if (i < 10) {
				k = i;
			}
			else {
				k = random3 % 10;
			}
			switch (k)
			{
			case 0:
				addOrganism(new Hogweed(this, { random1, random2 }));
				break;
			case 1:
				addOrganism(new Guarana(this, { random1, random2 }));
				break;
			case 2:
				addOrganism(new Milt(this, { random1, random2 }));
				break;
			case 3:
				addOrganism(new Grass(this, { random1, random2 }));
				break;
			case 4:
				addOrganism(new DeadlyNightshade(this, { random1, random2 }));
				break;
			case 5:
				addOrganism(new Antelope(this, { random1, random2 }));
				break;
			case 6:
				addOrganism(new Fox(this, { random1, random2 }));
				break;
			case 7:
				addOrganism(new Sheep(this, { random1, random2 }));
				break;
			case 8:
				addOrganism(new Wolf(this, { random1, random2 }));
				break;
			case 9:
				addOrganism(new Turtle(this, { random1, random2 }));
				break;
			default:
				break;
			}
		}
	}
}

void World::startCalopalenie() {
	for (int i = 0; i < Organisms.size(); i++) {
		if (dynamic_cast<Human*> (Organisms[i])) {
			Human* tmp = dynamic_cast<Human*> (Organisms[i]);
			if (tmp->getLasting() == 5) {
				string comment = "Human starts calopalenie.";
				this->log(comment);
				tmp->calopalenie();
				if (tmp->getBreak_() != 5) tmp->addBreak_(5);
			}
		}
	}
}

void World::handleTurn(int direction) {
	for (int i = 0; i < Organisms.size(); i++) {
		if (dynamic_cast<Human*>(Organisms[i])) {
			Human* tmp = dynamic_cast<Human*>(Organisms[i]);
			tmp->action(direction);
			if (tmp->getLasting() < 5 && tmp->getLasting() > 0) {
				tmp->calopalenie();
			}
			else if (tmp->getBreak_() > 0) {
				tmp->addBreak_(-1);
			}
			else {
				tmp->setLasting(5);
			}
		}
		else if (dynamic_cast<Hogweed*>(Organisms[i])) {
			Hogweed* tmp = dynamic_cast<Hogweed*>(Organisms[i]);
			tmp->action();
		}
		else Organisms[i]->action();

	}
	for (int i = 0; i < Organisms.size(); i++) {
		Organisms[i]->addAge(1);
	}
	this->turn++;
}

void World::printWorld() {
	system("cls");
	cout << "Dawid Glazik\tenter - next turn, q - quit, c - calopalenie, arrows - movement, s - save, l - load" << endl;
	for (int i = 0; i < width + 2; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < this->height; i++) {
		cout << "|";
		for (int k = 0; k < this->width; k++) {
			board[i][k]->print();
		}
		cout << "|";
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "-";
	}
	cout << "\nturn(" << this->turn << ").log: " << endl;
	for (int i = 0; i < Organisms.size(); i++) {
		if (dynamic_cast<Human*>(Organisms[i])) {
			Human* tmp = dynamic_cast<Human*>(Organisms[i]);
			if (tmp->getLasting() !=0 && tmp->getLasting() != 5) cout << "Calopalenie active: " << tmp->getLasting() << " turn(s)." << endl;
			if (tmp->getLasting() == 0 && tmp->getBreak_() != 0)cout << "Calopalenie available " << tmp->getBreak_() << " turn(s)." << endl;
		}
	}
	cout << this->console;
	this->console = "";
	//printOrganisms();
}

void World::addOrganism(Organism* new_) {
	this->board[new_->getCoords().x][new_->getCoords().y] = new_;
	if (Organisms.size() == 0) Organisms.push_back(new_);
	else {
		for (int i=0;i<Organisms.size();i++){
			if (new_->getInitiative() > Organisms[i]->getInitiative()) {
				auto indeks = find(Organisms.begin(), Organisms.end(), Organisms[i]);
				Organisms.insert(indeks, new_);
				return;
			}
		}
		Organisms.push_back(new_);
	}
}

void World::printOrganisms() {
	for (int i = 0; i < Organisms.size(); i++) {
		cout << Organisms[i]->getName() << " - ";
	}
}

void World::log(string console) {
	this->console += console;
	this->console += "\n";
}

int World::getWidth() {
	return width;
}

int World::getHeight() {
	return height;
}

void World::save() {
	fstream file;
	string fileName;
	cout << "Insert file name: "; 
	cin >> fileName;
	file.open(fileName, ios::out);
	if (file.good() == true)
	{
		file << this->turn << " " << this->width << " " << this->height << " " << Organisms.size() << endl;
		for (int i = 0; i < Organisms.size(); i++) {
			file << Organisms[i]->getName() << " " << Organisms[i]->getCoords().x << " " << Organisms[i]->getCoords().y << " " << Organisms[i]->getStrength() << " " << Organisms[i]->getAge() << " ";
			if (dynamic_cast<Human*>(Organisms[i])) {
				Human* tmp = dynamic_cast<Human*> (Organisms[i]);
				file << tmp->getLasting() << " " << tmp->getBreak_();
			}
			file << endl;
		}
		file.close();
	}
}

void World::load() {
	fstream file;
	string fileName;
	cout << "Podaj nazwe fileu do odczytu: ";
	cin >> fileName;
	file.open(fileName, ios::in);
	if (file.good() == true)
	{
		int rozmiar;
		string name;
		int x, y, age, strength, break_, lasting;
		for (int i = 0; i < height; i++) delete board[i];
		delete[] board;
		Organisms.clear();
		file >> this->turn >> this->width >> this->height >> rozmiar;
		this->Organisms.reserve(width * height);
		board = new Organism * *[height];
		for (int i = 0; i < height; i++) {
			board[i] = new Organism * [width];
		}
		for (int i = 0; i < height; i++) {
			for (int  j= 0; j < width; j++) board[i][j] = new Field(this, { j, i });
		}
		for (int i = 0; i < rozmiar; i++) {
			file >> name >> x >> y >> age >> strength;
			if (name == "Hogweed") {
				addOrganism(new Hogweed(this, { x, y }, age));
			}
			else if (name == "Guarana") {
				addOrganism(new Guarana(this, { x, y }, age));
			}
			else if (name == "Milt") {
				addOrganism(new Milt(this, { x, y }, age));
			}
			else if (name == "Grass") {
				addOrganism(new Grass(this, { x, y }, age));
			}
			else if (name == "Deadly_Nightshade") {
				addOrganism(new DeadlyNightshade(this, { x, y }, age));
			}
			else if (name == "Antelope") {
				addOrganism(new Antelope(this, { x, y }, strength, age));
			}
			else if (name == "Fox") {
				addOrganism(new Fox(this, { x, y }, strength, age));
			}
			else if (name == "Sheep") {
				addOrganism(new Sheep(this, { x, y }, strength, age));
			}
			else if (name == "Wolf") {
				addOrganism(new Wolf(this, { x, y }, strength, age));
			}
			else if (name == "Turtle") {
				addOrganism(new Turtle(this, { x, y }, strength, age));
			}
			else if (name == "Human") {
				file >> lasting >> break_;
				addOrganism(new Human(this, { x, y }, strength, age, lasting, break_));
			}
		}
		file.close();
	}
}

World::~World() {
	for (int i = 0; i < this->height; i++) {
		delete[] board[i];
	}
	delete[] board;
}