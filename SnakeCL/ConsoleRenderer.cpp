#include "pch.h"
#include "ConsoleRenderer.h"


ConsoleRenderer::ConsoleRenderer(Scene* _scene){
	scene=_scene;
}

void ConsoleRenderer::draw(){
	printf("Rendering\n");
	for(int x=0; x<Scene::WIDTH; x++){
		for(int y=0; y<Scene::HEIGHT; y++){
			switch(scene->field[y][x]){
				case FOOD:
					sceneStrings[y][x]='*';
					break;
				case TAIL:
					sceneStrings[y][x]='O';
					break;
				case EMPTY:
				default:
					sceneStrings[y][x]=' ';
					break;
			}
		}
	}
	moveCursor(std::cout, 1, 1);
	printf("Drawing\n");

	for(int i=0; i<Scene::WIDTH; i++){
		printf("_");
	}
	printf("\n");
	for(int y=0; y<Scene::HEIGHT; y++){
		printf("|");
		for(int x=0; x<Scene::WIDTH; x++){
			printf("%c", sceneStrings[y][x]);
		}
		printf("|\n");
	}
	for(int i=0; i<Scene::WIDTH; i++){
		printf("_");
	}
	printf("\n");
}

void ConsoleRenderer::moveCursor(std::ostream& os, int col, int row){
	os<<"\033["<<col<<";"<<row<<"H";
}