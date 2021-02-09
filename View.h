#pragma once
#include "Controller.h"

class View
{
public:
	View() {};
	View(Controller controller) { this->controller = controller; }

	void MainMenu();
	void PlayerList();
	void HeroList();
	void TeamList();
	void SessionList();

private:
	Controller controller;
};
