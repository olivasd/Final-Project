/*********************************************************************
** Program Filename: space.cpp
** Author: Daniel Olivas
** Date: 12/6/2016
** Description: Space is a parent class. Space has a pure virtual
** function that is passed to derived classes
*********************************************************************/
#ifndef SPACE_H
#define SPACE_H
#include <string>
class Player;

class Space {
protected:
	Space *left;
	Space *right;
	Space *forward;
	Space *back;
		
public:
	Space() 
	{
		left = NULL;
		right = NULL;
		forward = NULL;
		back = NULL;
	};
	void setLeft(Space *space)
	{
		left = space;
	};
	void setRight(Space *space)
	{
		right = space;
	};
	void setForward(Space *space)
	{
		forward = space;
	};
	void setBack(Space *space)
	{
		back = space;
	};
	virtual void specialAction(Player*) = 0;

};
#endif // !SPACE_H