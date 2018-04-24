/*********************************************************************
** Program Filename: player.cpp
** Author: Daniel Olivas 
** Date: 12/6/2016
** Description: Player has the pointer that points to the current location
** Player also has time variable that handles the "clock" of game. 
** Player also has a bag array that holds gathered items
*********************************************************************/

#include "player.h"

Player::Player()
{
	time = 15;
	count = 0;
	hasKey = false;
	for (int i = 0; i < 4; i++)
	{
		bag[i] = " ";
	}
}
/*********************************************************************
** Function: setRoom
** Description: setter function for the space
*********************************************************************/

void Player::setRoom(Space *newRoom)
{
	room = newRoom;
}
/*********************************************************************
** Function: getRoom
** Description: Return room
*********************************************************************/

Space * Player::getRoom()
{
	return room;
}
/*********************************************************************
** Function: getTime
** Description: returns time
*********************************************************************/

int Player::getTime()
{
	return time;
}
/*********************************************************************
** Function: setTime
** Description: time setter function
*********************************************************************/

void Player::setTime(int newTime)
{
	time = newTime;
}
/*********************************************************************
** Function: getHasKey
** Description: bool function returns hasKey 
*********************************************************************/

bool Player::getHasKey()
{
	return hasKey;
}
/*********************************************************************
** Function:  setHasKey
** Description: setter function for hasKey
*********************************************************************/

void Player::setHasKey(bool key)
{
	hasKey = key;
}
/*********************************************************************
** Function:  addItem
** Description: addItem adds string to bag array
*********************************************************************/

void Player::addItem(std::string item)
{
	bag[count] = item;
	count++;
}
/*********************************************************************
** Function: displayBag
** Description: Displays the contents of bag array
*********************************************************************/

void Player::displayBag()
{
	if (count == 0)
	{
		std::cout << "The bag is empty\n\n";
	}
	else
		for (int i = 0; i < count; i++)
		{
			std::cout << i + 1 << ". " << bag[i] << "\n";
		}
	std::cout << "\n";
}