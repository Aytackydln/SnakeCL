#include "pch.h"
#include "Scene.h"
#include <iostream>


snakeResult Scene::moveSnake(){
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
	tileType nextTile=field[nextY][nextX];
	switch(nextTile){
		case FOOD:
		case EMPTY:
		case TAIL:
		default:
			snake.extend(nextX,nextY);
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
}

Scene::Scene(){
	snakeDirection=RIGHT;
}


Scene::~Scene(){
}
