#include "pch.h"
#include "Tail.h"


Tail::Tail(int _x, int _y, Tail * _next){
	x=_x;
	y=_y;
	next=_next;
}


Tail::~Tail(){
	if(previous)previous->next=0;
	delete next;
}
