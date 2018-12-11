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
	nextX%=WIDTH;
	nextY%=HEIGHT;
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
	moveSnake();

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
				search=false;
				break;
		}
	}
	foods.push_back(randX);
	foods.push_back(randY);
	field[randY][randX]=FOOD;
}

Scene::Scene(){
	snakeDirection=RIGHT;
	createRandomFood();
}


Scene::~Scene(){
}
