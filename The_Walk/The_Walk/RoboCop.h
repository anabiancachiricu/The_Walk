#pragma once
#ifndef ROBOCOP_H_
#define ROBOCOP_H_
#include "Map.h"
#include "Robot.h"
#include<string>
#include<iostream>
using namespace std;

class RoboCop :public Robot
{
	static int i, j;
public:
	
	RoboCop(string);
	string getRoboCopType() { return Robot::getType(); }
	void Move(Map&);
};
#endif //!ROBOCOP_H_
/*Robocop este un politist robot mai special. 
El ii vaneaza pe Wall_e si Eve pentru ca ii suspecteaza ca nu si-au dus treaba la bun sfarsit.
El este imun la capcanele de gunoi care ii ranesc pe Wall_E si Eve.
El poate sari de pe ultima celula a unui rand pe prima a urmatorului, si se poate clona.
Din acest motiv, el va ajunge intotdeaua la finish.
El lasa cate o clona in fiecare loc pe unde trece, pentru a fi sigur ca ii printe pe cei 2 daca apar. */