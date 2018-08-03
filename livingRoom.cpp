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
}

void LivingRoom::welcome(){
	if (!hasBeen){
		std::cout << "***Welcome to the living room***\n";
		hasBeen = true;
	}
	else
		std::cout << "***Welcome back to the living room***\n";
}

char LivingRoom::menu(){
	char select;
	std::cout << "Choose your next move from the following list:\n"
		<< "1. Check inside the sofa\n2. Check the coffee table\n3. Move to the hall\n"
		<< "4. Move to the Kitchen\n5. Move to the bathroom\n"
		<< "6. Go outside\n7. Check your bag\nSelection: ";
	std::cin >> select;
	return select;
}

void LivingRoom::sofaPrompt(Player *player){
	if (!checkSofa){
		std::cout << "You are checking inside the sofa.\n";
		std::cout << "You did not find the key, but you did find your fast pass.\n"
			<< "This will give you more time to find your keys.\n\n";
		checkSofa = true;
		player->addItem("fast pass");
		winTime(player, 3);
	}
	else
		std::cout << "You have already checked the sofa and are wasting time.\n\n";
		loseTime(player, 1);
}

void LivingRoom::coffeeTablePrompt(Player *player){
	if (!checkCoffeeTable){
		std::cout << "You are checking the coffee table, but no keys are found.\n\n";
		checkCoffeeTable = true;
	}
	else
		std::cout << "You have already checked the coffee table and are wasting time.\n\n";
}

void LivingRoom::loseTime(Player *player, int timeLost){
		int time = player->getTime();
		time -= timeLost;
		player->setTime(time);
	}
void LivingRoom::winTime(Player *player, int timeWon){
		int time = player->getTime();
		time += timeWon;
		player->setTime(time);
	}

/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the living room
*********************************************************************/

void LivingRoom::specialAction(Player *player)
{
	char select;
	welcome();
	do
	{
		select = menu();
		switch (select)
		{
		case '1':
			sofaPrompt(player);
			break;
		case '2':
			coffeeTablePrompt(player);
			loseTime(player, 1);
			break;
		case '3':
			loseTime(player, 1);
			player->setRoom(forward); //moves to the hall
			break;
		case '4':
			loseTime(player, 1);
			player->setRoom(right);  //moves to the kitchen
			break;
		case '5':
			loseTime(player, 1);
			player->setRoom(left);  //moves to the bathroom
			break;
		case '6':
			loseTime(player, 1);
			player->setRoom(back);  //moves to outside
			break;
		case '7':
			player->displayBag();
			loseTime(player, 1);
			break;
		default:
			std::cout << "Invalid selection.\n";			
		}
	} while (select != '3' && select != '4' && select != '5' && select != '6');
}