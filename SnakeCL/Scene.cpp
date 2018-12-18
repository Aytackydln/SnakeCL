#include "pch.h"
#include "Scene.h"


snakeResult Scene::moveSnake(){
	if(GetAsyncKeyState(VK_UP))snakeDirection=UP;
	if(GetAsyncKeyState(VK_DOWN))snakeDirection=DOWN;
	if(GetAsyncKeyState(VK_LEFT))snakeDirection=LEFT;
	if(GetAsyncKeyState(VK_RIGHT))snakeDirection=RIGHT;
	snakeResult result=NOTHING;
	int nextX=snake.getX();
	int nextY=snake.getY();
	switch(snakeDirection){
		case RIGHT:
			nextX++;
			break;
		case LEFT:
			nextX--;
			break;
		case DOWN:
			nextY++;
			break;
		case UP:
			nextY--;
			break;
		default:
			break;
	}
	if(nextX!=-1)nextX%=WIDTH;
	else nextX=WIDTH-1;
	if(nextY!=-1)nextY%=HEIGHT;
	else nextY=HEIGHT-1;
	tileType nextTile=field[nextY][nextX];
	switch(nextTile){
		case TAIL:
			result=FAIL;
			break;
		case FOOD:
			snake.extend(nextX, nextY);
			foods.clear();
			createRandomFood();
			break;
		case EMPTY:
			snake.extend(nextX, nextY);
			snake.removeLastTail();
			break;
		default:
			break;
	}
	return result;
}

void Scene::updateField(){
	if(moveSnake()!=FAIL){
		for(int x=0; x<WIDTH; x++){
			for(int y=0; y<HEIGHT; y++){
				field[y][x]=EMPTY;
			}
		}

		Tail* nextTail=snake.tailStart;
		while(nextTail){
			field[nextTail->y][nextTail->x]=TAIL;
			nextTail=nextTail->next;
		}
		for(int i=0; i<foods.size(); i+=2){
			const int x=foods[i];
			const int y=foods[i+1];
			field[y][x]=FOOD;
		}
	} else{
		initialize();
		snake.initialize();
	}
}

void Scene::createRandomFood(){
	int randX=std::rand()%WIDTH;
	int randY=std::rand()%HEIGHT;
	bool search=true;
	while(search){
		switch(field[randY][randX]){
			case EMPTY:
				search=false;
				break;
			case FOOD:
			case TAIL:
			default:
				randX=std::rand()%WIDTH;
				randY=std::rand()%HEIGHT;
				break;
		}
	}
	foods.emplace_back(randX);
	foods.emplace_back(randY);
	field[randY][randX]=FOOD;
}

void Scene::initialize(){
	for(int x=0; x<WIDTH; x++){
		for(int y=0; y<HEIGHT; y++){
			field[y][x]=EMPTY;
		}
	}
}

Scene::Scene(){
	initialize();
	snakeDirection=RIGHT;
	createRandomFood();
}

Scene::~Scene(){
}
