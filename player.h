/*********************************************************************
** Program Filename: player.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: Header file for Player
*********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "space.h"

class Player {
private:
	Space *room;
	std::string bag[4];
	int count;
	int time;
	bool hasKey;
public:
	Player();
	void setRoom(Space *);
	Space *getRoom();
	int getTime();
	void setTime(int);
	bool getHasKey();
	void setHasKey(bool);
	void addItem(std::string);
	void displayBag();
};

#endif // !PLAYER_H
