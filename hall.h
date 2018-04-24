/*********************************************************************
** Program Filename: hall.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: Header file for hall
*********************************************************************/

#ifndef HALL_H
#define HALL_H
#include <iostream>
#include <string>
#include "space.h"
#include "player.h"

class Hall : public Space {
private:
	std::string room;
	bool hasBeen;
	bool checkedPlant;
	int time;
public:
	Hall();
	void specialAction(Player *);
};
#endif // !HALL_H

