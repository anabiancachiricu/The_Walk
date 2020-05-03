#pragma once
#ifndef WALL_E_H_
#define WALL_E_H_
#include "Map.h"
#include "Robot.h"
#include<string>
#include<iostream>
using namespace std;

class Wall_E:public Robot
{
	static int i, j;
public:
	//Wall_E();
	Wall_E(string);
	string getWall_eType() { return Robot::getType(); }
	void Move(Map&);
};
#endif //!WALL_E_H_

/*Robotul Wall-E are o munca grea de facut. Acesta parcurge toata harta pana ajunge la finish. 
El poate merge doar spre dreapta daca se afla pe un rand par, sau spre stanga in cazul unui rand impar.
Daca ajung la capatul randului, are posibilitatea de a sari peste celula de fix dedesubt, doar in cazul in care acolo se afla gunoi.
In cazul in care se afla gunoi atat in celula de sub el, cat si in urmatoarea pe care trebuie sa o parcurga, acesta poate sa sara peste cea de dedesubt i sa ajunga 
in cea de pe diagonala, dar colecteaza gunoiul si isi pierde o viata, deoarece este prea mult si nu il poate ridica.
El poate sa stranga maxim 3 gunoie, dupa care isi pierde viata, fara sa indeplineasca misiunea.
Pentru fiecare celula care urmeaza, acesta verifica daca a ajuns la finish sau daca urmeaza o capcana de gunoi. 
In cazul in care a ajuns la finish, Wall-E se opreste si sarbatoreste victoria.
In cazul in care a ajuns la o celula goala, isi contiunua linistit drumul.*/