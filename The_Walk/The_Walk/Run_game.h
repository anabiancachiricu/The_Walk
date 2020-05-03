#pragma once
#ifndef _RUN_GAME_H_
#define _RUN_GAME_H_
#include <string>
#include<iostream>
#include"Robot.h"

#include"Eve.h"
#include"Wall_E.h"
#include"Map.h"
using namespace std;
class Run_game
{
	Map* map;
	Robot* rob;
public:
	Run_game();
	~Run_game();
};

#endif // !_RUN_GAME_H_


