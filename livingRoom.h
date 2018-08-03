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
	void welcome();
	char menu();
	void sofaPrompt(Player *);
	void coffeeTablePrompt(Player *);
	void loseTime(Player *player, int timeLost);
	void winTime(Player *player, int timeWon);	
};

#endif // LIVINGROOM_H