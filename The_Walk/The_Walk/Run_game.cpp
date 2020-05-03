#include "Run_game.h"
#include<iostream>
#include"Robot.h"
#include"Run_game.h"
#include"Eve.h"
#include"Wall_E.h"
#include"Map.h"
#include"RoboCop.h"
using namespace std;

Run_game::Run_game()
{
	cout << "Se creaza jocul." << endl;
	map =new Map();
	cout << "Wall-E si Eve s-au ratacit printre gunoaie." << endl << "Ei si-au propus sa se intalneasca la pozitia de finish." << endl;
	cout << "Dar, pentru a ajunge acolo, trebuie sa treaca prin oras si sa supravietuiasca capcanelor toxice formate."<<endl;
	cout << "Vor reusi, oare, sa se regaseasca?" << endl;
	cout << "Alege robotul preferat si vei afla!" << endl;
	cout << "Pentru Wall-E, apasa 1"<<endl;
	cout << "Pentru Eve, apasa 2" << endl;
	cout << "Pentru RoboCop, apasa 3" << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << "L-ai ales pe Wall-E! Succes!" << endl;
		this->rob = new Wall_E("#1");
	}
	else
	{
		if (x == 2)
		{
			cout << "Ai ales-o pe Eve! Succes!" << endl;
			this->rob = new Eve("#2");
		}
		else
		{
			if (x == 3)
			{
				cout << "L-ai ales pe RoboCop! Bafta!" << endl;
				this->rob = new RoboCop("#3");
			}
			else
			{

				cout << "Cred ca robotul ales s-a ratacit. Alege din nou!" << endl;
			
			}
		}
	}
	rob->Move(*map);
}
Run_game::~Run_game() 
{
	delete  rob;
	delete map;
}