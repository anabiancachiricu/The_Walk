#include "Map.h"
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int Map::randNum(int inf, int sup)
{
	//srand((int)time(NULL));
	//return rand() % 50 + 1;
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type>dist(inf, sup);
	return dist(rng);

}

pair<int, int> Map::randPoz()
{
	//srand((int)time(NULL));
	int i = randNum(1, this->getNoRows()-1);
	int j = randNum(1, this->getNoCols()-1);
	return make_pair(i, j);
}

Map::Map()
{
	rows = randNum(15, 50);
	cols = rows;
	if (rows < 15) rows = 15;
	if (cols < 15) cols = 15;
	map = new char* [rows];
	for (int i = 0; i < rows; i++)
		map[i] = new char[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			map[i][j] = '_';

	map[0][0] = 'R';
	int noTraps = randNum(10, 30);
	pair <int, int> poz, fin;
	int i = 0;
	while( i < noTraps)
	{
		poz = randPoz();
		this->map[poz.first][poz.second] = 'T';
		i++;
	}
	
	fin = randPoz();
	map[fin.first][fin.second] = 'F';

}
void Map::generateTraps()
{
	int noTraps = randNum(10, 30);
	int i = 0;
	while(i < noTraps)
	{
		int j = randNum(1, this->getNoRows());
		int k = randNum(1, this->getNoCols());
		this->map[j][k] = 'T';
		i++;
	}
}
void Map::setNewValue(int i, int j, char c, Map &map)
{
	this->map[i][j] = c;
}
pair<int, int> Map::getFinish(Map& map)
{
	for (int i = 0; i < this->getNoRows(); i++)
		for (int j = 0; j < this->getNoCols(); j++)
			if (this->map[i][j] == 'F')
				return make_pair(i, j);
}

int Map::getNoRows() const
{
	return rows;
}
int Map::getNoCols() const
{
	return cols;
}
char Map::getValue(int i, int j)
{
	return this->map[i][j];
}
void Map::print(Map &map)
{
	for (int i = 0; i < map.rows; i++)
	{
		for (int j = 0; j < map.cols; j++)
			cout << this->map[i][j] << " ";
		cout << endl;
	}
}
Map::~Map()
{
	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	this->rows = 0;
	this->cols = 0;
}
void Map::move_robot(const pair<int, int> poz1, const pair<int, int> poz2)
{
	map[poz1.first][poz1.second] = '_';
	map[poz2.first][poz2.second] = 'R';
}