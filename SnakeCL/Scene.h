#pragma once
#include "Snake.h"
#include <vector>
#include <iostream>
#include <random>
#include <Windows.h>

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
	std::vector<int> foods;
public:
	static const int WIDTH=15;
	static const int HEIGHT=10;
	tileType field[HEIGHT][WIDTH];
	Snake snake;
	void updateField();
	void createRandomFood();
	Scene();
	~Scene();
};

