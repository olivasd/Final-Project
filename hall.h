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
public:
	Hall();
	void specialAction(Player *);
	void welcome();
	char menu();
	void plantPrompt(Player *);
	void loseTime(Player *player, int timeLost);
	void winTime(Player *player, int timeWon);	
};
#endif // !HALL_H

