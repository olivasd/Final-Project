/*********************************************************************
** Program Filename: livingRoom.cpp
** Author: Daniel Olivas 
** Date: 12/6/2016
** Description: living room is a Space in the game. It is the location 
**  where the user starts. The living room has the hall forward, kitchen
**	to the right, bathroom to the left, and outside in the back.
*********************************************************************/

#include "livingRoom.h"

// constructor
LivingRoom::LivingRoom()
{
	room = "living room";
	hasBeen = false;
	checkSofa = false;
	checkCoffeeTable = false;
	time = 0;
}

/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the living room
*********************************************************************/

void LivingRoom::specialAction(Player *player)
{
	char select;
	if (!hasBeen)
	{
		std::cout << "***Welcome to the living room***\n";
		hasBeen = true;
	}
	else
	{
		std::cout << "***Welcome back to the living room***\n";
	}
	do
	{
		std::cout << "Choose your next move from the following list:\n"
			<< "1. Check inside the sofa\n2. Check the coffee table\n3. Move to the hall\n"
			<< "4. Move to the Kitchen\n5. Move to the bathroom\n"
			<< "6. Go outside\n7. Check your bag\nSelection: ";
		std::cin >> select;
		switch (select)
		{
		case '1':
			if (!checkSofa)
			{
				std::cout << "You are checking inside the sofa.\n";
				std::cout << "You did not find the key, but you did find your fast pass.\n"
					<< "This will give you more time to find your keys.\n\n";
				time = player->getTime();
				time += 3;
				player->setTime(time);
				checkSofa = true;
				player->addItem("fast pass");
			}
			else
			{
				std::cout << "You have already checked the sofa and are wasting time.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '2':
			if (!checkCoffeeTable)
			{
				std::cout << "You are checking the coffee table, but no keys are found.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
				checkCoffeeTable = true;
			}
			else
			{
				std::cout << "You have already checked the coffee table and are wasting time.\n\n";
				time = player->getTime();
				time--;
				player->setTime(time);
			}
			break;
		case '3':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(forward); //moves to the hall
			break;
		case '4':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(right);  //moves to the kitchen
			break;
		case '5':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(left);  //moves to the bathroom
			break;
		case '6':
			time = player->getTime();
			time--;
			player->setTime(time);
			player->setRoom(back);  //moves to outside
			break;
		case '7':
			player->displayBag();
			time = player->getTime();
			time--;
			player->setTime(time);
			break;
		default:
			std::cout << "Invalid selection.\n";			
		}
	} while (select != '3' && select != '4' && select != '5' && select != '6');
}