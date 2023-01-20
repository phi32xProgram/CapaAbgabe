#ifndef MATERIALIEN_CPP_
#define MATERIALIEN_CPP_

#include <iostream>
#include <string>
using namespace std;

//Materialien Klassen
class Material {
public:
	double price;
	int anzahl = 0;
	int bezeichner;
	double getPrice() {
		return price;
	}
	int getBezeichner() {
		return bezeichner;
	}
};
class Kunststoff : public Material {
public:
	Kunststoff() {
		price = 2.50;
		anzahl++;
		bezeichner = 2;
	}
	int getAnzahl() {
		return anzahl;
	}
	double getPrice() {
		return price;
	}
	int getBezeichner() {
		return bezeichner;
	}
};

class Holz : public Material {
public:
	Holz() {
		price = 3.50;
		anzahl++;
		bezeichner = 0;
	}
	int getAnzahl() {
		return anzahl;
	}
	double getPrice() {
		return price;
	}
	int getBezeichner() {
		return bezeichner;
	}
};

class Metall : public Material {
public:
	Metall() {
		price = 5.00;
		anzahl++;
		bezeichner = 1;
	}
	int getAnzahl() {
		return anzahl;
	}
	double getPrice() {
		return price;
	}
	int getBezeichner() {
		return bezeichner;
	}
};



#endif

