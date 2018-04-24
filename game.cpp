/*********************************************************************
** Program Filename: game.cpp
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: game is called in main is runs the game
*********************************************************************/

#include "game.h"
//constructor
Game::Game()
{
	player = new Player();
	bathRoom = new BathRoom();
	bedRoom = new BedRoom();
	kitchen = new Kitchen();
	livingRoom = new LivingRoom();
	outside = new Outside();
	hall = new Hall();
	bathRoom->setForward(bedRoom);
	bathRoom->setRight(livingRoom);
	bedRoom->setRight(hall);
	bedRoom->setBack(bathRoom);
	kitchen->setLeft(livingRoom);
	livingRoom->setForward(hall);
	livingRoom->setRight(kitchen);
	livingRoom->setBack(outside);
	livingRoom->setLeft(bathRoom);
	outside->setForward(livingRoom);
	hall->setBack(livingRoom);
	hall->setLeft(bedRoom);
	player->setRoom(livingRoom);
}
//destructor
Game::~Game()
{
	delete player;
	delete bathRoom;
	delete bedRoom;
	delete kitchen;
	delete livingRoom;
	delete outside;
	delete hall;
}
/*********************************************************************
** Function: intro
** Description: intro gives the intro to the game
*********************************************************************/

void Game::intro()
{
	std::cout << "It is just a typical Monday morning. You woke up, brushed your teeth, took a\n"
		<< "shower, get dressed. Check the clock, awesome you are actually 5 minutes early.\n"
		<< "The boss will surely appreciate that. You are about to walking out the door and\n"
		<< " oh no, the car keys are not on the key hook.\n\n"
		<< "Objective: Find your car keys before time runs out and you are late for work.\n\n"
		<< "FOR GRADER: THE KEYS ARE IN THE BEDROOM DRESSER\n\n";
}
/*********************************************************************
** Function: playGame
** Description: playGame dymically allocates intences of each space.
** Points Space to connected Space.
** A while loop is run while the player time is not 0 (lost game)
** or 100(won game).
*********************************************************************/

void Game::playGame()
{
	
	while (player->getTime() > 0 && player->getTime() != 100)
	{
		int time = player->getTime();  //time * 3 == 1 minute
				std::cout << "*****you have " << time / 3 << " minutes remaining*****\n"; //displays minutes left with Space changes
		player->getRoom()->specialAction(player);
	}
	if (player->getTime() <= 0)
	{
		std::cout << "\nYou have run out of time.\n"
			<< "You will no longer be able to make to work on time\n"
			<< "*****GAME OVER*****";
	}
}
