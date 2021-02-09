#pragma once
#include "Controller.h"

class View
{
public:
	View(Controller controller) { this->controller = controller; }

	char MainMenu();
	void PlayerList();
	void HeroList();
	void TeamList();
	void SessionList();

private:
	Controller controller;
};
