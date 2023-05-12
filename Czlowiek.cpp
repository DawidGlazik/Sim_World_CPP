#include "Czlowiek.h"
#include "Pole.h"

Czlowiek::Czlowiek() {
	this->sila = 5;
	this->inicjatywa = 4;
	this->wiek = 0;
	this->trwanie = 5;
	this->przerwa = 0;
}

Czlowiek::Czlowiek(Swiat* swiat, Polozenie xy) {
	this->sila = 5;
	this->inicjatywa = 4;
	this->wiek = 0;
	this->swiat = swiat;
	this->xy = xy;
	this->trwanie = 5;
	this->przerwa = 0;
}

Czlowiek::Czlowiek(Swiat* swiat, Polozenie xy, int sila, int wiek, int trwanie, int przerwa) {
	this->sila = sila;
	this->inicjatywa = 4;
	this->wiek = wiek;
	this->swiat = swiat;
	this->xy = xy;
	this->trwanie = trwanie;
	this->przerwa = przerwa;
}

void Czlowiek::sprawdzIZabij(int x1, int y1) {
	string komentarz;
	if (!dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + x1][this->xy.y + y1])) {
		komentarz = "";
		komentarz += this->swiat->plansza[this->xy.x + x1][this->xy.y + y1]->getNazwa();
		komentarz += this->swiat->plansza[this->xy.x + x1][this->xy.y + y1]->getXY();
		komentarz += " zabity(a) przez (calopalenie) ";
		komentarz += this->getNazwa();
		komentarz += this->getXY();
		this->swiat->dziennik(komentarz);
		this->swiat->plansza[this->xy.x + x1][this->xy.y + y1] = new Pole();
		for (int i = 0; i < this->swiat->organizmy.size(); i++) {
			if (this->swiat->organizmy[i]->getPolozenie().x == this->xy.x + x1 && this->swiat->organizmy[i]->getPolozenie().y == this->xy.y + y1) {
				this->swiat->organizmy.erase(this->swiat->organizmy.begin() + i);
			}
		}
	}
}

void Czlowiek::akcja(int kierunek) {
	if (kierunek == 0) return;
	else if (kierunek == 1) {
		if (this->xy.x == 0) return;
		else {
			if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x - 1][this->xy.y])) {
				this->swiat->plansza[this->xy.x - 1][this->xy.y] = this->swiat->plansza[this->xy.x][this->xy.y];
				this->swiat->plansza[this->xy.x][this->xy.y] = new Pole();
				this->xy.x--;
			}
			else {
				this->swiat->plansza[this->xy.x - 1][this->xy.y]->kolizja(this);
			}
		}
	}
	else if (kierunek == 2) {
		if (this->xy.x == this->swiat->getWysokosc() - 1) return;
		else {
			if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x + 1][this->xy.y])) {
				this->swiat->plansza[this->xy.x + 1][this->xy.y] = this->swiat->plansza[this->xy.x][this->xy.y];
				this->swiat->plansza[this->xy.x][this->xy.y] = new Pole();
				this->xy.x++;
			}
			else {
				this->swiat->plansza[this->xy.x + 1][this->xy.y]->kolizja(this);
			}
		}
	}
	else if (kierunek == 3) {
		if (this->xy.y == 0) return;
		else {
			if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x][this->xy.y - 1])) {
				this->swiat->plansza[this->xy.x][this->xy.y - 1] = this->swiat->plansza[this->xy.x][this->xy.y];
				this->swiat->plansza[this->xy.x][this->xy.y] = new Pole();
				this->xy.y--;
			}
			else {
				this->swiat->plansza[this->xy.x][this->xy.y - 1]->kolizja(this);
			}
		}
	}
	else if (kierunek == 4) {
		if (this->xy.y == this->swiat->getSzerokosc() - 1) return;
		else {
			if (dynamic_cast<Pole*>(this->swiat->plansza[this->xy.x][this->xy.y + 1])) {
				this->swiat->plansza[this->xy.x][this->xy.y + 1] = this->swiat->plansza[this->xy.x][this->xy.y];
				this->swiat->plansza[this->xy.x][this->xy.y] = new Pole();
				this->xy.y++;
			}
			else {
				this->swiat->plansza[this->xy.x][this->xy.y + 1]->kolizja(this);
			}
		}
	}
}

void Czlowiek::rysowanie() {
	cout << 'C';
}

string Czlowiek::getNazwa() {
	return "Czlowiek";
}

int Czlowiek::getTrwanie() {
	return this->trwanie;
}

int Czlowiek::getPrzerwa() {
	return this->przerwa;
}

void Czlowiek::setTrwanie(int trwanie) {
	this->trwanie = trwanie;
}

void Czlowiek::addPrzerwa(int przerwa) {
	this->przerwa += przerwa;
}

void Czlowiek::calopalenie() {
	this->trwanie--;
	if (this->xy.x == 0) {
		if (this->xy.y == 0) {
			sprawdzIZabij(0, 1);
			sprawdzIZabij(1, 1);
			sprawdzIZabij(1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			sprawdzIZabij(0, -1);
			sprawdzIZabij(1, -1);
			sprawdzIZabij(1, 0);
		}
		else {
			sprawdzIZabij(0, -1);
			sprawdzIZabij(1, -1);
			sprawdzIZabij(1, 0);
			sprawdzIZabij(0, 1);
			sprawdzIZabij(1, 1);
		}
	}
	else if (this->xy.x == this->swiat->getWysokosc() - 1) {
		if (this->xy.y == 0) {
			sprawdzIZabij(0, 1);
			sprawdzIZabij(-1, 1);
			sprawdzIZabij(-1, 0);
		}
		else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
			sprawdzIZabij(0, -1);
			sprawdzIZabij(-1, -1);
			sprawdzIZabij(-1, 0);
		}
		else {
			sprawdzIZabij(0, 1);
			sprawdzIZabij(-1, 1);
			sprawdzIZabij(-1, 0);
			sprawdzIZabij(0, -1);
			sprawdzIZabij(-1, -1);
		}
	}
	else if (this->xy.y == 0) {
		sprawdzIZabij(0, 1);
		sprawdzIZabij(-1, 1);
		sprawdzIZabij(-1, 0);
		sprawdzIZabij(1, 1);
		sprawdzIZabij(1, 0);
	}
	else if (this->xy.y == this->swiat->getSzerokosc() - 1) {
		sprawdzIZabij(0, -1);
		sprawdzIZabij(-1, -1);
		sprawdzIZabij(-1, 0);
		sprawdzIZabij(1, -1);
		sprawdzIZabij(1, 0);
	}
	else {
		sprawdzIZabij(0, 1);
		sprawdzIZabij(1, 0);
		sprawdzIZabij(1, 1);
		sprawdzIZabij(-1, 0);
		sprawdzIZabij(-1, 1);
		sprawdzIZabij(-1, -1);
		sprawdzIZabij(0, -1);
		sprawdzIZabij(1, -1);
	}
}

Czlowiek::~Czlowiek() {

}