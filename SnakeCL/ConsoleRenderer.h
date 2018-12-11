#pragma once
#include "Scene.h"
class ConsoleRenderer{
private:
	Scene* scene;
	char sceneStrings[20][20];
public:
	ConsoleRenderer(Scene* _scene);

	void draw();
};
