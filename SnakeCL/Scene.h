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
	std::vector<int> foods;
public:
	direction snakeDirection;
	static const int WIDTH=20;
	static const int HEIGHT=15;
	tileType field[HEIGHT][WIDTH];
	Snake snake;
	void updateField();
	void createRandomFood();
	void initialize();
	Scene();
	~Scene();
};

