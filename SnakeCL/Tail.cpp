#include "pch.h"
#include "Tail.h"
#include <stdio.h>

Tail::Tail(int _x, int _y, Tail* _next){
	x=_x;
	y=_y;
	next=_next;
}


Tail::~Tail(){
	if(previous){
		previous->next=0;
	}
	if(next){
		next->previous=0;
		delete next;
	}

}
