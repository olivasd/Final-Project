/*********************************************************************
** Program Filename: livingRoom.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: Header file for LivingRoom
*********************************************************************/

#ifndef LIVINGROOM_H
#define LIVINGROOM_H
#include <iostream>
#include "space.h"
#include "player.h"

class LivingRoom : public Space {
private:
	std::string room;
	bool checkSofa;
	bool hasBeen;
	bool checkCoffeeTable;
	int time;
public:
	LivingRoom();
	void specialAction(Player *);
};

#endif // LIVINGROOM_H