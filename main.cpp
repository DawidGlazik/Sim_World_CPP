#include "Organism.h"
#include "Organisms.h"
#include <conio.h>
#include<stdio.h>
#include <Windows.h>

int main()
{
	World* world = new World(20, 10);
	world->printWorld();
	char x;
	int direction;
	while (x = _getch()) {
		switch (x)
		{
		case 0x48:
			direction = 1;	//up
			world->handleTurn(direction);
			break;
		case 0x50:
			direction = 2;	//down
			world->handleTurn(direction);
			break;
		case 0x4b:
			direction = 3;	//left
			world->handleTurn(direction);
			break;
		case 0x4d:
			direction = 4;	//right
			world->handleTurn(direction);
			break;
		case 'c':
			world->startCalopalenie();
			break;
		case 's':
			system("cls");
			world->save();
			break;
		case 'l':
			system("cls");
			world->load();
			break;
		case '\x0D': //enter
			world->handleTurn(0);
			break;
		case 'q':
			system("cls");
			cout << "Symulation has ended." << endl;
			return 0;
		default:
			break;
		}
		world->printWorld();
	}
	world->~World();
}