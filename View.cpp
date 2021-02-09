#pragma once
#include <iostream>
#include "View.h"


using namespace std;

int View::MainMenu()
{
	cout << "1)Player list\n\
			2)Hero list\n\
			3)Team list\n\
			4)Session list\n\
			Choose your destiny: ";
	char input;
	cin >> input;
	switch (input)
	{
	case 1:
		PlayerList();
		break;
	case 2:
		HeroList();
		break;
	case 3:
		TeamList();
		break;
	case 4:
		SessionList();
		break;
	default:
		cout << "Try again" << endl;
	}
}

void View::PlayerList()
{
	cout<<controller.GetPlayerList() << "Add new Player?(Y/N): ";
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
		controller.AddNewPlayer();
}

void View::HeroList()
{
	cout << controller.GetHeroList() << "Add new Hero?(Y/N): ";
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
		controller.AddNewHero();
}

void View::TeamList()
{
	cout << controller.GetTeamList() << "Add new Team?(Y/N): ";
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
		controller.AddNewTeam();
}

void View::SessionList()
{
	cout << controller.GetSessionList() << "Play new Match?(Y/N): ";
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
		controller.AddNewSession();
}
