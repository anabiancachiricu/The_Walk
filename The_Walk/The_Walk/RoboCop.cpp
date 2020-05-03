#include "RoboCop.h"
#include<iostream>
using namespace std;

int RoboCop::i = 0;
int RoboCop::j = 0;

RoboCop::RoboCop(string nr) :Robot(nr) {}
void RoboCop::Move(Map& map)
{
	pair<int, int> poz = this->getPosition();
	pair<int, int> poz2;				//initializez pozitia pe care vreau sa ajung
	int r = map.getNoRows();
	int c = map.getNoCols();
	int ok = 0;                        //variabila care verifica daca a ajuns la final
	int stop = 0;						//variabila care verifica daca mai are vieti
	int nrRunda = 1;
	poz = this->getPosition();
	i = poz.first;
	j = poz.second; 
	ok = 0;
	while (ok == 0)
	{
		i = poz.first;
		j = poz.second;
		if (map.getValue(i, j) == 'F')
		{
			ok = 1;
		}
		else
		{
			if (j < c - 1)
			{
				if (map.getValue(i, j + 1) == 'F')
				{
					ok = 1;
					poz2 = make_pair(i, j + 1);
				}
				else
				{
					poz2 = make_pair(i, j + 1);
				}
			}
			else
			{
				j = 0;
				if (map.getValue(i + 1, j) == 'F')
				{
					ok = 1;
					poz2 = make_pair(i + 1, j);
				}
				else
				{
					poz2 = make_pair(i + 1, j);
				}
			}
			
		}
	
		int i = poz.first;
		int j = poz.second;
		int i2 = poz2.first;
		int j2 = poz2.second;
		poz = poz2;
		map.move_robot(poz, poz2);
		map.print(map);
		cout << "Runda " << ' ' << nrRunda << endl << "RoboCop s-a clonat de pe pozitia (" << i << ',' << j << ") si pe pozitia (" << i2 << ',' << j2 << ')' << endl;
		cout << endl;
		//system("pause");
		nrRunda++;
		poz = poz2;
	}
}