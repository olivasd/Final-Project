/*********************************************************************
** Program Filename: outside.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: Header file for Outside
*********************************************************************/

#ifndef OUTSIDE_H
#define OUTSIDE_H
#include <iostream>
#include "space.h"
#include "player.h"

class Outside : public Space {
private:
	std::string room;

public:
	Outside();
	void specialAction(Player *);
	char menu();
	void welcome();
	void loseTime(Player *player, int timeLost);
	void winTime(Player *player, int timeWon);	
};
#endif // !OUTSIDE_H

