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
	while(true){
		scene.updateField();
		renderer.draw();
		Sleep(200);
	}
}
