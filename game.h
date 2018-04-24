/*********************************************************************
** Program Filename: game.h
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: header file for game
*********************************************************************/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "player.h"
#include "space.h"
#include "bathRoom.h"
#include "bedRoom.h"
#include "kitchen.h"
#include "livingRoom.h"
#include "outside.h"
#include "hall.h"

class Game {
private:
	Player *player;
	Space *bathRoom;
	Space *bedRoom;
	Space *kitchen;
	Space *livingRoom;
	Space *outside;
	Space *hall;
	
public:
	Game();
	~Game();
	void intro();
	void playGame();
};
#endif // !GAME_H
