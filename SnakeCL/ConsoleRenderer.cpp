#include "pch.h"
#include "ConsoleRenderer.h"
#include <iostream>


ConsoleRenderer::ConsoleRenderer(Scene* _scene){
	scene=_scene;
}

void ConsoleRenderer::draw(){
	printf("Rendering\n");
	for(int x=0; x<Scene::WIDTH; x++){
		for(int y=0; y<Scene::HEIGHT; y++){
			switch(scene->field[y][x]){
				case TAIL:
					sceneStrings[y][x]='T';
					break;
				case EMPTY:
				default:
					sceneStrings[y][x]=' ';
					break;
			}
		}
	}

	system("CLS");
	printf("Drawing\n");

	for(int i=0; i<Scene::HEIGHT; i++){
		//printf("s%s\n", sceneStrings[i]);
		printf("s%s\n", sceneStrings[i]);
	}
}
