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
}

void BathRoom::welcome(){
	if(!hasBeen){

		std::cout << "***Welcome to the bathroom***\n";
		std::cout << "Oh no, you just looked in the mirror "
			<< "and your hair is a mess.\n"
			<< "You are short on time, but you have to fix your hair\n\n";
		hasBeen = true;
	}
	else{
		std::cout << "***Welcome back to the bathroom***\n";
	}
}

char BathRoom::menu(){
	char select;
	std::cout << "Choose your next move from the following list:\n"
			<< "1. Check the medicine cabinet\n2. Check under the sink\n3. Move to the bedroom\n"
			<< "4. Move to the living room\n5. Check your bag\nSelection: ";
	std::cin >> select;
	return select;
}

void BathRoom::cabinetPrompt(){	
	if (!checkCabinet){
		std::cout << "You are checking the medicine cabinet, but no keys are found.\n\n";		
		checkCabinet = true;
	} 
	else
		std::cout << "You have already checked the medicine cabinet and are wasting time.\n\n";			
}

void BathRoom::underSinkPrompt(){
	if (!checkUnderSink){
		std::cout << "You are checking under the sink, but no keys are found.\n\n";
		checkUnderSink = true;
	}
	else			
		std::cout << "You have already checked under the sink and are wasting time.\n\n";
}

void BathRoom::loseTime(Player *player, int timeLost){
		int time = player->getTime();
		time -= timeLost;
		player->setTime(time);
	}
void BathRoom::winTime(Player *player, int timeWon){
		int time = player->getTime();
		time += timeWon;
		player->setTime(time);
	}

/*********************************************************************
** Function: specialAction
** Description: Special action welcomes the player, and has a do while
** loop while the user is selecting places to check in the bathroom
*********************************************************************/

void BathRoom::specialAction(Player *player)
{
	char select;
	if(!hasBeen){
		loseTime(player, 3);
	}
	welcome();
	do{
		select = menu();
		switch (select)
		{
		case '1':
			cabinetPrompt();
			loseTime(player, 1);
			break;
		case '2':
			underSinkPrompt();
			loseTime(player, 1);
			break;
		case '3':
			player->setRoom(forward); // moves to bedroom
			loseTime(player, 1);
			break;
		case '4':
			player->setRoom(right); // moves to living room
			loseTime(player, 1);
			break;
		case '5':
			player->displayBag();
			loseTime(player, 1);
			break;
		default:
			std::cout << "Invalid selection\n";
		}
	} while (select != '3' && select != '4');
}
