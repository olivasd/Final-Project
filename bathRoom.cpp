/*********************************************************************
** Program Filename: bathRoom.cpp
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: bathroom is a space that in the game. Bathroom has the 
** living room on the left and the bedroom forward.
*********************************************************************/
#include "bathRoom.h"
//constructor
BathRoom::BathRoom()
{
	room = "bathroom";
	hasBeen = false;
	checkCabinet = false;
	checkUnderSink = false;
	time = 0;
}
/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the bathroom
*********************************************************************/

void BathRoom::specialAction(Player *player)
{
	char select;
	if (!hasBeen)
	{
		std::cout << "***Welcome to the bathroom***\n";
		std::cout << "Oh no, you just looked in the mirror "
			<< "and your hair is a mess.\n"
			<< "You are short on time, but you have to fix your hair\n\n";
		time = player->getTime();
		time -= 3;
		player->setTime(time);
		hasBeen = true;
	}
	else
	{
		std::cout << "***Welcome back to the bathroom***\n";
	}
	do
	{
		std::cout << "Choose your next move from the following list:\n"
			<< "1. Check the medicine cabinet\n2. Check under the sink\n3. Move to the bedroom\n"
			<< "4. Move to the living room\n5. Check your bag\nSelection: ";
			std::cin >> select;
			switch (select)
			{
			case '1':
				if (!checkCabinet)
				{
					std::cout << "You are checking the medicine cabinet, but no keys are found.\n\n";
					time = player->getTime();
					time--;
					player->setTime(time);
					checkCabinet = true;
				}
				else
				{
					std::cout << "You have already checked the medicine cabinet and are wasting time.\n\n";
					time = player->getTime();
					time--;
					player->setTime(time);
				}
				break;
			case '2':
				if (!checkUnderSink)
				{
					std::cout << "You are checking under the sink, but no keys are found.\n\n";
					time = player->getTime();
					time--;
					player->setTime(time);
					checkUnderSink = true;
				}
				else
				{
					std::cout << "You have already checked under the sink and are wasting time.\n\n";
					time = player->getTime();
					time--;
					player->setTime(time);
				}
				break;
			case '3':
				player->setRoom(forward); // moves to bedroom
				time = player->getTime();
				time--;
				player->setTime(time);
				break;
			case '4':
				player->setRoom(right); // moves to living room
				time = player->getTime();
				time--;
				player->setTime(time);
				break;
			case '5':
				player->displayBag();
				time = player->getTime();
				time--;
				player->setTime(time);
				break;
			default:
				std::cout << "Invalid selection\n";
			}
	} while (select != '3' && select != '4');
}
