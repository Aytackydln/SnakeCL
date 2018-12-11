#include "pch.h"
#include "Snake.h"


void Snake::update(snakeResult result){
	switch(result){
		case NOTHING:
			removeLastTail();
			break;
		case EAT:
			break;
		default:
			break;
	}
}

int Snake::getX(){
	return tailStart->x;
}

int Snake::getY(){
	return tailStart->y;
}

void Snake::extend(int _x, int _y){
	tailStart=new Tail(_x, _y, tailStart);
	if(!secondLastTail){
		secondLastTail=tailStart;
	}
}

void Snake::removeLastTail(){
	delete secondLastTail->next;
	secondLastTail->next=0;
}

Snake::Snake(){
	tailStart=new Tail();
	tailEnd=tailStart;
}

Snake::~Snake(){
	delete tailStart;
}
