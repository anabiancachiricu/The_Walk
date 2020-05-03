#pragma once
#ifndef ROBOT_H_
#define ROBOT_H_
#include<string>
using namespace std;
#include "Map.h"
class Map;
class Robot
{
	string nr;
	static int lives;
	pair<int, int> position;

protected:
	void setNewPosition(pair<int, int> );

public:
	friend class Map;
	Robot();
	Robot(string);
	virtual ~Robot();
	pair<int, int> getPosition();
	virtual void Move(Map&)=0;		//metoda virtuala pura de mutare a robotului 
	virtual string getType();
	void decrementLives();
	int getLives();
};
#endif //!ROBOT_H_



