#define FOOD_FREQ = 6

#include "pch.h"
#include "Scene.h"
#include "ConsoleRenderer.h"
#include <iostream>
#include <windows.h>

int main()
{
	Scene scene;
	ConsoleRenderer renderer(&scene);
    std::cout << "Hello World!\n"; 
	while(true){
		printf("updating field\n");
		scene.updateField();
		printf("starting draw\n");
		renderer.draw();
		Sleep(1000);
	}
}
