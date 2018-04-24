/*********************************************************************
** Program Filename: bedRoom.cpp
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: bedRoom is a Space in the game. bedRoom has the Hall
** to the right and bathRoom back.
*********************************************************************/

#include "bedRoom.h"
//constructor
BedRoom::BedRoom()
{
	room = "bedroom";
	hasBeen = false;
	checkDresser = false;
	checkCloset = false;
	checkBed = false;
}
/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the bedroom
*********************************************************************/
void BedRoom::specialAction(Player *player)
{
	char select;
	if (!hasBeen)
	{

		std::cout << "***Welcome to the bedroom***\n";
		hasBeen = true;
	}
	else
	{
		std::cout << "***Welcome back to the bedroom***\n";
	}
	do
	{
		std::cout << "Please select from the following choices\n"
			<< "1. Check the bed\n2. Check the dresser\n3. Check the closet\n"
			<< "4. Move to the bathroom\n5. Move to the hall\n6. Check your bag\nSelection: ";
		std::cin >> select;
		switch (select) 
		{
		case '1':
			if (!checkBed)
			{
				checkBed = true;
				std::cout << "You are checking the bed, no keys are found.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			else
			{
				std::cout << "You have checked the bed and are wasting time.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '2':
			if (!checkDresser)
			{
				std::cout << "You are checking the dresser...\n";
				std::cout << "YOU HAVE DONE IT, YOU HAVE FOUND THE KEYS!\n"
					<< "Get outside as fast as you can to make it to work on time!\n\n";
				checkDresser = true;
				player->setHasKey(checkDresser);
				time = player->getTime();
				time--;
				player->setTime(time);
				player->addItem("keys");
			}
			else
			{
				std::cout << "You have already found the key here,\nget outside as fast as you can.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '3':
			if (!checkCloset)
			{
				checkCloset = true;
				std::cout << "You are checking the closet, no keys are found.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			else
			{
				std::cout << "You have checked the closet and are wasting time.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '4':
			time = player->getTime(); 
			time--;
			player->setTime(time);
			player->setRoom(back); //move to bathroom
			break;
		case '5':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(right); //move to hall
			break;
		case '6':
			player->displayBag();
			time = player->getTime();
			time--;
			player->setTime(time);
			break;
		default:
                std::cout << "Invalid selection\n";
		}
	} while (select != '4' && select != '5');
}
