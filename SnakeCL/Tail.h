#pragma once
class Tail{
public:
	int x;
	int y;
	Tail* next;
	Tail( int _x=2, int _y=2, Tail* _next=0);
	~Tail();
};

