#pragma once
#include "Snake.h"
enum tileType{
	TAIL, FOOD, EMPTY
};
enum direction{
	UP, RIGHT, DOWN, LEFT
};
class Scene{
private:
	snakeResult moveSnake();
	direction snakeDirection;
public:
	static const int WIDTH=15;
	static const int HEIGHT=10;
	tileType field[HEIGHT][WIDTH];
	Snake snake;
	void updateField();
	Scene();
	~Scene();
};

