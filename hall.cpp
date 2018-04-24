/*********************************************************************
** Program Filename: hall.cpp
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: hall is a space that in the game. Hall has bedroom on 
** the left and living room back.
*********************************************************************/

#include "hall.h"

Hall::Hall()
{
	room = "hall";
	hasBeen = false;
	checkedPlant = false;
	time = 0;
}
/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the hall
*********************************************************************/
void Hall::specialAction(Player *player)
{
	char select;
	if (!hasBeen)
	{
		std::cout << "***Welcome to the hall***\n";
		hasBeen = true;
	}
	else
	{
		std::cout << "***Welcome back to the hall***\n";
	}
	do
	{
		std::cout << "Choose your next move from the following list:\n"
			<< "1. Check inside the hall plant\n2. Move to the bedroom\n"
			<< "3. Move to the living room\n4. Check your bag\nSelection: ";
		std::cin >> select;
		switch (select)
		{
		case '1':
			if (!checkedPlant)
			{
				std::cout << "You are checking the plant, but the keys are not there.\n";
				std::cout << "You do notice a beautiful flower has sprouted.\n"
					<< "You can pick the flower to give to your boss, so she may overlook\n"
					<< "you being a few minutes late.\n\n";
				checkedPlant = true;
				time = player->getTime();
				time += 3;
				player->setTime(time);
				player->addItem("flower");
			}
			else
			{
				std::cout << "You have checked the plant and are wasting time.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '2':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(left); // moves to bedroom
			break;
		case '3':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(back); //moves to living room
			break;
		case '4':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->displayBag();
			break;
		default:
			std::cout << "Invalid selection\n";
		}
	} while (select != '2' && select != '3');
}

