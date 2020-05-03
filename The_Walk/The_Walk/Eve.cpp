#include "Eve.h"
int Eve::i = 0;
int Eve::j = 0;
Eve::Eve(string nr) :Robot(nr) {}
void Eve::Move(Map& map)
{
	pair<int, int> poz = this->getPosition();
	pair<int, int> poz2;				//initializez pozitia pe care vreau sa ajung
	int r = map.getNoRows();
	int c = map.getNoCols();
	int ok = 0;                        //variabila care verifica daca a ajuns la final
	int stop = 0;						//variabila care verifica daca mai are vieti
	int nrRunda = 1;
	poz = this->getPosition();
	
	while (ok == 0 && stop == 0)
	{		i = poz.first;
			j = poz.second;
			
			if (j % 2 == 0)
			{
				if (i < r - 1 && j < c - 1)
				{
					if (map.getValue(i + 1, j) == 'F')
					{
						ok = 1;
						poz2 = make_pair(i + 1, j);
					}
					else
					{
						if (map.getValue(i + 1, j) == 'T')
						{
							this->decrementLives();
							if (this->getLives() == 0)
							{
								cout <<"Eve a fost invinsa de gunoaie";
								stop = 1;
								break;
							}
							else
								poz2 = make_pair(i + 1, j);
						}
						else
						{
							poz2 = make_pair(i + 1, j);
						}
					}

				}
				else
				{
					if (i == r - 1 && j < c - 1)
					{
						if (map.getValue(i, j + 1) == 'F')
						{
							ok = 1;
							poz2 = make_pair(i, j + 1);
						}
						else
						{
							if (map.getValue(i, j + 1) == 'T')
							{
								this->decrementLives();
								if (this->getLives() == 0)
								{
									cout << "Eve a fost invinsa de gunoaie";
									stop = 1;
									break;
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
						if (i < r - 1 && j == c - 1)
						{
							if (map.getValue(i + 1, j) == 'F')
							{
								ok = 1;
								poz2 = make_pair(i + 1, j);
							}
							else
							{
								if (map.getValue(i + 1, j) == 'T')
								{
									this->decrementLives();
									if (this->getLives() == 0)
									{
										cout << "Eve a fost invinsa de gunoaie";
										stop = 1;
										break;
									}
									else
										poz2 = make_pair(i + 1, j);
								}
								else
								{
									poz2 = make_pair(i + 1, j);
								}
							}
						}
					}
				}
			}
			else
			{
				if (i > 0 && j < c - 1)
				{
					if (map.getValue(i - 1, j) == 'F')
					{
						ok = 1;
						poz2 = make_pair(i - 1, j);
					}
					else
					{
						if (map.getValue(i - 1, j) == 'T')
						{
							this->decrementLives();
							if (this->getLives() == 0)
							{
								cout << "Eve a fost invinsa de gunoaie";
								stop = 1;
								break;
							}
							else
								poz2 = make_pair(i - 1, j);
						}
						else
						{
							poz2 = make_pair(i - 1, j);
						}

					}
				}
				else
				{
					if (i == 0 && j < c - 1)
					{
						if (map.getValue(i, j + 1) == 'F')
						{
							ok = 1;
							poz2 = make_pair(i, j + 1);
						}
						else
						{
							if (map.getValue(i, j + 1) == 'T')
							{
								this->decrementLives();
								if (this->getLives() == 0)
								{
									cout << "Eve a fost invins de gunoaie";
									stop = 1;
									break;
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
						if (i > 0 && j == c - 1)
						{
							if (map.getValue(i - 1, j) == 'F')
							{
								ok = 1;
								poz2 = make_pair(i - 1, j);
							}
							else
							{
								if (map.getValue(i - 1, j) == 'T')
								{
									this->decrementLives();
									if (this->getLives() == 0)
									{
										cout << "Eve a fost invinsa de gunoaie";
										stop = 1;
										break;
									}
									else
										poz2 = make_pair(i - 1, j);
								}
								else
								{
									poz2 = make_pair(i - 1, j);
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
			
			map.move_robot(poz, poz2);
			map.print(map);
			cout << "Runda " << ' ' << nrRunda << endl << "Eve s-a mutat de pe pozitia (" << i << ',' << j << ") pe pozitia (" << i2 << ',' << j2 << ')' << endl;
			cout << endl;
			system("pause");
			nrRunda++;
			poz = poz2;
			
		
	}
	if (ok) cout << "Eve a ajuns la destinatie!";
	if (stop) cout << "Din pacate, Eve nu a reusit sa ajunga la Wall-E";
}