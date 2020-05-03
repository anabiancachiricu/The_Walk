#pragma once
#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#include "Robot.h"
#include<random>

class Map
{
	int rows;
	int cols;
	char** map;
public:
												//constructor pentru harta 
	Map();
												//constructor de copiere
	Map(const Map& m);
												//destructor pt harta
	~Map();
	void generateTraps();
	char** generateMap(int rows, int cols);		//initializarea hartii si popularea ei cu capcane
	void print(Map& map);						//printarea hartii
	void setFinish(Map& map);
	pair<int, int> getFinish(Map &map);
	char getValue(int i, int j);					//functie care determina elementul de pe o pozitie
	void setNewValue(int i, int j, char c, Map& map);
	int getNoRows() const;							//functie care determina nr de randuri
	int getNoCols() const;							//functie care determina numarul de coloane
	//pair<int, int> getFinish() const;
	int randNum(int, int);								//functie care genereaza un numar random
	pair<int, int> randPoz();					//functie care genereaza o pereche random

	void move_robot(const pair<int, int>, const pair<int, int>);	//functie care muta robotul
};

#endif // !MAP_H_