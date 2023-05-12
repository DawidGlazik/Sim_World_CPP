#include "Organizm.h"
#include "Organizmy.h"
#include <conio.h>
#include<stdio.h>
#include <Windows.h>

int main()
{
	Swiat* swiat = new Swiat(20, 10);
	swiat->rysujSwiat();
	char x;
	int kierunek;
	while (x = _getch()) {
		switch (x)
		{
		case 0x48:
			kierunek = 1;	//up
			swiat->wykonajTure(kierunek);
			break;
		case 0x50:
			kierunek = 2;	//down
			swiat->wykonajTure(kierunek);
			break;
		case 0x4b:
			kierunek = 3;	//left
			swiat->wykonajTure(kierunek);
			break;
		case 0x4d:
			kierunek = 4;	//right
			swiat->wykonajTure(kierunek);
			break;
		case 'c':
			swiat->rozpocznijCalopalenie();
			break;
		case 's':
			system("cls");
			swiat->zapisz();
			break;
		case 'l':
			system("cls");
			swiat->wczytaj();
			break;
		case '\x0D': //enter
			swiat->wykonajTure(0);
			break;
		case 'q':
			system("cls");
			cout << "Symulacja zakonczona." << endl;
			return 0;
		default:
			break;
		}
		swiat->rysujSwiat();
	}
	swiat->~Swiat();
}