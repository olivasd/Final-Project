/*********************************************************************
** Program Filename: bathRoom.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: header file for bathRoom
*********************************************************************/

#ifndef BATHROOM_H
#define BATHROOM_H
#include "space.h"
#include "player.h"

class BathRoom : public Space {
private:
	std::string room;
	bool hasBeen;
	bool checkCabinet;
	bool checkUnderSink;
	int time;
public:
	BathRoom();
	void specialAction(Player *);
};
#endif // !BATHROOM_H