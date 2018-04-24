/*********************************************************************
** Program Filename: kitchen.cpp
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: kitchen is a space in the game. Kitchen has living
**   room on the right.
*********************************************************************/

#include "kitchen.h"
//constructor
Kitchen::Kitchen()
{
	room = "kitchen";
	checkCabinet = false;
	checkFridge = false;
	hasBeen = false;
	time = 0;
}
/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the kitchen
*********************************************************************/

void Kitchen::specialAction(Player *player)
{
	char select;
	if (!hasBeen)
	{
		std::cout << "***Welcome to the kitchen***\n";
		hasBeen = true;
	}
	else
	{
		std::cout << "***Welcome back to the kitchen***\n";
	}
	do
	{
		std::cout << "Choose your next move from the following list:\n"
			<< "1. Check inside the cabinets\n2. Check inside the refrigerator\n"
			<< "3. Move to the living room\n4. Check your bag\nSelection: ";
		std::cin >> select;
		switch (select)
		{
		case '1':
			if (!checkCabinet)
			{
				std::cout << "You are checking the cabinets, but no keys are found.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
				checkCabinet = true;
			}
			else
			{
				std::cout << "You have already checked the cabinets and are wasting time.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '2':
			if (!checkFridge)
			{
				std::cout << "You are checking the cabinets, but no keys are found.\n";
				std::cout << "You did find your bosses favorite cookies though.\n"
					<< "With the cookies, your boss will overlook being a couple minutes late.\n\n";
				time = player->getTime();
				time += 3;
				player->setTime(time);
				player->addItem("cookies");
				checkFridge = true;
			}
			else
			{
				std::cout << "You have already checked the refrigerator and are wasting time.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '3':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(left); // moves to the living room
			break;
		case '4':
			player->displayBag();
			time = player->getTime();
			time--;
			player->setTime(time);
			break;
		default:
			std::cout << "Invalid selection\n";
		}
	} while (select != '3');
}

