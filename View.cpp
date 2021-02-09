#pragma once
#include <iostream>
#include "View.h"

using namespace std;

void View::MainMenu()
{
	cout << "1)Player list\n"
		<< "2)Hero list\n"
		<< "3)Team list\n"
		<< "4)Session list\n"
		<< "Choose your destiny: ";
	char input;
	cin >> input;
	switch (input)
	{
	case '1':
		PlayerList();
		break;
	case '2':
		HeroList();
		break;
	case '3':
		TeamList();
		break;
	case '4':
		SessionList();
		break;
	default:
		cout << "Try again" << endl;
	}
}

void View::PlayerList()
{
	cout<<controller.GetPlayerList() << "1)Add new Player\n"
									<<"2)Delete Player\n"
									<<"3)Back\n"
									<<"Choise: ";
	char input;
	cin >> input;
	switch (input)
	{
	case '1':
		controller.AddNewPlayer();
		break;
	case '2':
		controller.DeletePlayer();
	}
}

void View::HeroList()
{
	cout << controller.GetHeroList() << "1)Add new Hero\n"
		<< "2)Delete Hero\n"
		<< "3)Back\n"
		<< "Choise: ";
	char input;
	cin >> input;
	switch (input)
	{
	case '1':
		controller.AddNewHero();
		break;
	case '2':
		controller.DeleteHero();
	}
}

void View::TeamList()
{
	cout << controller.GetTeamList() << "1)Create new Team\n"
		<< "2)Delete Team\n"
		<< "3)Back\n"
		<< "Choise: ";
	char input;
	cin >> input;
	switch (input)
	{
	case '1':
		controller.AddNewTeam();
		break;
	case '2':
		controller.DeleteTeam();
	}
}

void View::SessionList()
{
	cout << controller.GetSessionList() << "Play new Match?(Y/N): ";
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
		controller.AddNewSession();
}
