#include "Robot.h"
#include"Map.h"

int Robot::lives = 3;
Robot::Robot() : nr(" "), position({ 0, 0 }) {}
Robot::Robot(string s) : nr("#" + s), position({ 0, 0 }) {}

Robot::~Robot()
{
	this->nr = " ";
	this->position = { -1, -1 };
}

void Robot::setNewPosition(pair<int, int> newPosition)
{
	this->position.first = newPosition.first;
	this->position.second = newPosition.second;
}
pair<int, int> Robot::getPosition()
{
	return this->position;
}

string Robot::getType()
{
	this->nr = "#" + nr;
	return this->nr;
 }
void Robot::decrementLives()
{
	this->lives--;

}
int Robot::getLives()
{
	return this->lives;
}