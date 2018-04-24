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
		std::cout << "Oh no, you have locked yourself out!";
		player->setTime(0);
	}
	else
	{
		std::cout << "****YOU WIN****\nYou are going to make it to work on time!\n";
		player->setTime(100);
	}
}