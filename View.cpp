#pragma once
#include <iostream>
#include "View.h"

using namespace std;

void View::MainMenu()
{
	cout << "\n\n1)Player list\n"
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
	std::string name;
	int id;
	switch (input)
	{
	case '1':
		cout << "Id: ";
		cin >> id;
		cout << "Name: ";
		cin >> name;
		controller.AddNewPlayer(id, name);
		PlayerList();
		break;
	case '2':
		cout << "Id: ";
		cin >> id;
		controller.DeletePlayer(id);
		PlayerList();
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
	std::string name;
	int id,hp,dmg;
	switch (input)
	{
	case '1':
		cout << "Id: ";
		cin >> id;
		cout << "Name: ";
		cin >> name;
		cout << "HP: ";
		cin >> hp;
		cout << "DMG: ";
		cin >> dmg;
		controller.AddNewHero(id, name, hp, dmg);
		HeroList();
		break;
	case '2':
		cout << "Id: ";
		cin >> id;
		controller.DeleteHero(id);
		HeroList();
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
	string name;
	int playerId[5];
	switch (input)
	{
	case '1':
		cout << "Team Name: ";
		cin >> name;
		for (int i = 0; i < 5; ++i)
		{
			cout << "Player " << i << " Id: ";
			cin >> playerId[i];
		}
		controller.AddNewTeam(name, playerId);
		TeamList();
		break;
	case '2':
		cout << "Team Name: ";
		cin >> name;
		controller.DeleteTeam(name);
		TeamList();
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
