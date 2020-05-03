#pragma once
#ifndef EVE_H_
#define EVE_H_
#include "Map.h"
#include "Robot.h"
#include<string>
#include<iostream>
using namespace std;

class Eve :public Robot
{
	static int i, j;
public:
	Eve(string);
	string getEveType() { return Robot::getType(); }
	void Move(Map&);
};
#endif //!EVE_H_

/*Eve pleaca in cautarea lui Wall-E, dar intelege gresit si parcurge alt traseu. 
Ea spera ca se vor intalni la Finish, dar intampina niste obstacole pe parcurs. 
Stiind ca treaba lui Wall-E e sa stranga gunoaiele, aceasta nu incearca sa le ocoleasca, ci trece prin ele, pierzand cate o viata.
Ea parcurge harta diferit, mergand intai pe pprima coloana in jos, apoi pe a 2-a in sus, pe a 3-a in jos si tot asa pana este doborata de gunoi sau ajunge la finish unde se intalneste cu Wall-E. */