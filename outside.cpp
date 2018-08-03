/*********************************************************************
** Program Filename: outside.cpp
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: Outside is a Space in the game. Outside is the ending 
** space to win the game. The player enter outside before having key
** will result in a loss. 
*********************************************************************/

#include "outside.h"
//constructor
Outside::Outside()
{
	room = "outside";
}

char Outside::menu(){}
	
void Outside::welcome(){};

void Outside::loseTime(Player *player, int timeLost){
	int time = player->getTime();
	time -= timeLost;
	player->setTime(time);
}
void Outside::winTime(Player *player, int timeLost){
	player->setTime(100);
}

/*********************************************************************
** Function: specialAction
** Description: If the player has not reteived the key, then they are locked
** out and player time is set to 0(lose the game). If the player gets outside
** with the key, they are declared a winner.
*********************************************************************/

void Outside::specialAction(Player *player)
{
	if (!player->getHasKey())
	{
		std::cout << "Oh no, you have locked yourself out!\n";
		loseTime(player, player->getTime());
	}
	else
	{
		std::cout << "****YOU WIN****\nYou are going to make it to work on time!\n";
		winTime(player, 100);
	}
}