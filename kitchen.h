/*********************************************************************
** Program Filename: kitchen.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: Header file for kitchen
*********************************************************************/

#ifndef KITCHEN_H
#define KITCHEN_H
#include "space.h"
#include "player.h"

class Kitchen : public Space {
private:
	std::string room;
	bool checkCabinet;
	bool checkFridge;
	bool hasBeen;
public:
	Kitchen();
	void specialAction(Player *);
	void welcome();
	char menu();
	void cabinetPrompt(Player *);
	void fridgePrompt(Player *);
	void loseTime(Player *player, int timeLost);
	void winTime(Player *player, int timeWon);	
};
#endif // !KITCHEN_H

