#pragma once
#include "Tail.h"
enum snakeResult{
	NOTHING, FAIL, EAT
};
class Snake{
public:
	int length;
	Tail* tailStart;
	Tail* tailEnd;
	Tail* secondLastTail;
	void update(snakeResult result);
	int getX();
	int getY();
	void extend(int _x, int _y);
	void removeLastTail();
	Snake();
	~Snake();
};

