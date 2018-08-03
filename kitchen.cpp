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
}

void Kitchen::welcome(){
	if (!hasBeen){
		std::cout << "***Welcome to the kitchen***\n";
		hasBeen = true;
	}
	std::cout << "***Welcome back to the kitchen***\n";
}

char Kitchen::menu(){
	char select;
	std::cout << "Choose your next move from the following list:\n"
		<< "1. Check inside the cabinets\n2. Check inside the refrigerator\n"
		<< "3. Move to the living room\n4. Check your bag\nSelection: ";
	std::cin >> select;
	return select;
}

void Kitchen::cabinetPrompt(Player *player){
	if (!checkCabinet){
		std::cout << "You are checking the cabinets, but no keys are found.\n\n";
		checkCabinet = true;
	}
	else
		std::cout << "You have already checked the cabinets and are wasting time.\n\n";		
}

void Kitchen::fridgePrompt(Player *player){
	if (!checkFridge){
		std::cout << "You are checking the fridge, but no keys are found.\n";
		std::cout << "You did find your bosses favorite cookies though.\n"
			<< "With the cookies, your boss will overlook being a couple minutes late.\n\n";
		player->addItem("cookies");
		winTime(player, 3);
		checkFridge = true;
	}
	else{
		std::cout << "You have already checked the refrigerator and are wasting time.\n\n";
		loseTime(player, 1);
	}
}

void Kitchen::loseTime(Player *player, int timeLost){
		int time = player->getTime();
		time -= timeLost;
		player->setTime(time);
	}
void Kitchen::winTime(Player *player, int timeWon){
		int time = player->getTime();
		time += timeWon;
		player->setTime(time);
	}
/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the kitchen
*********************************************************************/

void Kitchen::specialAction(Player *player)
{
	char select;
	welcome();
	do
	{
		select = menu();
		switch (select)
		{
		case '1':
			cabinetPrompt(player);
			loseTime(player, 1);
			break;
		case '2':
			fridgePrompt(player);
			break;
		case '3':
			loseTime(player, 1);
			player->setRoom(left); // moves to the living room
			break;
		case '4':
			player->displayBag();
			loseTime(player, 1);
			break;
		default:
			std::cout << "Invalid selection\n";
		}
	} while (select != '3');
}