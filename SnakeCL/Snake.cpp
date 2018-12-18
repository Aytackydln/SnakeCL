#include "pch.h"
#include "Snake.h"
#include <stdio.h>


void Snake::update(snakeResult result){
	/*
	switch(result){
		case NOTHING:
			removeLastTail();
			break;
		case EAT:
			break;
		default:
			break;
	}
	*/
}

int Snake::getX(){
	return tailStart->x;
}

int Snake::getY(){
	return tailStart->y;
}

void Snake::extend(int _x, int _y){
	length++;
	tailStart->previous=new Tail(_x, _y, tailStart);
	tailStart=tailStart->previous;
}

void Snake::removeLastTail(){
	Tail* tailToRemove=tailEnd;
	tailEnd=tailToRemove->previous;
	delete tailToRemove;
}

Snake::Snake(){
	initialize();
}

Snake::~Snake(){
	delete tailStart;
}

void Snake::initialize(){
	if(tailStart) delete tailStart;
	tailStart=new Tail();
	tailEnd=tailStart;
}
