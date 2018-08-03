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
	bool hasBeen;
	bool checkCloset;
	bool checkDresser;
	bool checkBed;
public:
	BedRoom();
	void specialAction(Player *);
	void welcome();
	char menu();
	void bedPrompt();
	void dresserPrompt(Player *);
	void closetPrompt();
	void loseTime(Player *player, int timeLost);
	void winTime(Player *player, int timeWon);	
};
#endif // !BEDROOM_H
