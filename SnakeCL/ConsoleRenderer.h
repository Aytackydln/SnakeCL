#pragma once
#include "Scene.h"
#include <iostream>
#include <windows.h>

class ConsoleRenderer{
private:
	Scene* scene;
	char sceneStrings[Scene::HEIGHT][Scene::WIDTH];
public:
	ConsoleRenderer(Scene* _scene);

	void draw();
	void moveCursor(std::ostream & os, int col, int row);
};
