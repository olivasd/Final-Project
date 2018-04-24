/*********************************************************************
** Program Filename: bedRoom.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: header file for bedRoom
*********************************************************************/

#ifndef BEDROOM_H
#define BEDROOM_H
#include "space.h"
#include "player.h"

class BedRoom : public Space{
private:
	std::string room;
	int time;
	bool hasBeen;
	bool checkCloset;
	bool checkDresser;
	bool checkBed;
public:
	BedRoom();
	void specialAction(Player *);
};
#endif // !BEDROOM_H
