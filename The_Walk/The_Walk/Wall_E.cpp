#include "Wall_E.h"
#include<iostream>
using namespace std;

int Wall_E::i = 0;
int Wall_E::j = 0;

Wall_E::Wall_E(string nr) :Robot(nr) {}
void Wall_E::Move(Map& map)
{
	pair<int, int> poz=this->getPosition();
	pair<int, int> poz2;				//initializez pozitia pe care vreau sa ajung
	int r = map.getNoRows();
	int c = map.getNoCols();
	int ok = 0;                        //variabila care verifica daca a ajuns la final
	int stop = 0;						//variabila care verifica daca mai are vieti
	int nrRunda = 1;
	poz = this->getPosition();
		
	while (ok==0 && stop==0)
	{	
		i = poz.first;
		j = poz.second;
		
		if (i % 2 == 0)
		{
			if (j < c-1 && i<r-1)
			{
				if (map.getValue(i, j+1) == 'F')
				{
					poz2 = make_pair(i, j + 1);
					ok = 1;
				}
				else
				{
					if (map.getValue(i, j + 1) == 'T')
					{
						this->decrementLives();
						if (this->getLives() == 0)
						{
							cout << "Wall_E a fost invins de gunoaie";
							stop = 1;
						}
						else
							poz2 = make_pair(i, j + 1);
					}
					else
					{
						poz2 = make_pair(i, j + 1);
					}
				}
			}
			else
			{
				if (j == c - 1 && i < r - 1)
				{
					if (map.getValue(i + 1, j) == 'F')
					{
						ok = 1;
						poz2 = make_pair(i + 1, j);
					}
					else
					{
						if (map.getValue(i + 1, j - 1) == 'F')
						{
							ok = 1;
							poz2 = make_pair(i + 1, j - 1);
						}
						else
						{
							if (map.getValue(i + 1, j) == 'T')
							{
								if (map.getValue(i + 1, j - 1) == 'T')
								{
									this->decrementLives();
									if (this->getLives() == 0)
									{
										cout << "Wall_E a fost invins de gunoaie";
										stop = 1;
									}
									else
										poz2 = make_pair(i+1, j - 1);
								}
								else
								{
									poz2 = make_pair(i + 1, j - 1);
								}
							}
							else
							{
								poz2 = make_pair(i + 1, j);
							}
						}
					}
				}
				else
				{
					if (j < c - 1 && i == r - 1)
					{
						if (map.getValue(i, j + 1) == 'F')
						{
							ok = 1;;
							poz2 = make_pair(i, j + 1);
						}
						else
						{
							if (map.getValue(i, j + 1) == 'T')
							{
								this->decrementLives();
								if (this->getLives() == 0)
								{
									cout << "Wall_E a fost invins de gunoaie";
									stop = 1;
								}
								else
									poz2 = make_pair(i, j + 1);
							}
							else
								poz2 = make_pair(i, j + 1);
						}
					}
				}
			}
		}
		else
		{
			if (j > 0 && i > r - 1)
			{
				if (map.getValue(i, j - 1) == 'F')
				{
					ok = 1;
					poz2 = make_pair(i, j - 1);
				}
				else
				{
					if (map.getValue(i, j - 1) == 'T')
					{
						this->decrementLives();
						if (this->getLives() == 0)
						{
							cout << "Wall_E a fost invins de gunoaie";
							stop = 1;
						}
						else
							poz2 = make_pair(i, j - 1);
					}
					else
					{
						poz2 = make_pair(i, j - 1);
					}
				}
			}
			else
			{
				if (j == 0 && i > r - 1)
				{
					if (map.getValue(i + 1, j) == 'F')
					{
						ok = 1;
						poz2 = make_pair(i + 1, j);
					}
					else
					{
						if (map.getValue(i + 1, j + 1) == 'F')
						{
							ok = 1;
							poz2 = make_pair(i + 1, j + 1);
						}
						else
						{
							if (map.getValue(i + 1, j) == 'T')
							{
								if (map.getValue(i + 1, j + 1) == 'T')
								{
									this->decrementLives();
									if (this->getLives() == 0)
									{
										cout << "Wall_E a fost invins de gunoaie";
										stop = 1;
									}
									else
										poz2 = make_pair(i+1, j + 1);
								}
								else
								{
									poz2 = make_pair(i + 1, j + 1);
								}

							}
							else
							{
								poz2 = make_pair(i + 1, j);
							}
						}
					}
				}
				else
				{
					if (j > 0 && i == r - 1)
					{
						if (map.getValue(i, j - 1) == 'F')
						{
							ok = 1;
							poz2 = make_pair(i, j - 1);
						}
						else
						{
							if (map.getValue(i, j - 1) == 'F')
							{
								this->decrementLives();
								if (this->getLives() == 0)
								{
									cout << "Wall_E a fost invins de gunoaie";
									stop = 1;
								}
								else
									poz2 = make_pair(i, j - 1);
							}
							else
							{
								poz2 = make_pair(i, j - 1);
							}
						}
					}
				}
			}
		}
		int i = poz.first;
		int j = poz.second;
		int i2 = poz2.first;
		int j2 = poz2.second;
		cout << "Runda " << ' ' << nrRunda << endl<<"Wall-E s-a mutat de pe pozitia ("<<i<<','<<j<<") pe pozitia ("<<i2<<','<<j2<<')'<<endl;
		map.move_robot(poz, poz2);
		map.print(map);
		nrRunda++;
		poz = poz2;
		cout << "Inca o runda?" << endl;
		cout << "Apasa 1 pentru a continua, 2 pentru a renunta" << endl;
		int x;
		cin >> x;
		if (x == 2) break;
		if (x != 1 && x != 2)
		{
			cout << "Wall_E nu a inteles, deci se opreste." << endl; 
			break;
			
		}

	}
	if (ok) cout << "Wall-E a ajuns la Final!";
	if (stop) cout << "Wall-E nu a reusit sa ajunga la destinatie.";
}