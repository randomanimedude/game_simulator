#pragma once
#include <iostream>
#include "View.h"

using namespace std;

bool View::MainMenu()
{
	cout << "\n\n1)Player list\n"
		<< "2)Hero list\n"
		<< "3)Team list\n"
		<< "4)Session list\n"
		<< "5)Exit\n"
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
	case '5':
		return false;
	default:
		cout << "Try again" << endl << endl;
	}
	return true;
}

void View::PlayerList()
{
	char input;
	string name;
	int id;

	cout << controller.GetPlayerList();
	bool repeat;
	do {
		repeat = false;
		cout << "1)Add new Player\n"
			<< "2)Delete Player\n"
			<< "3)Back\n"
			<< "Choice: ";
		cin >> input;
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
			break;
		case '3':
			break;
		default:
			cout << "Try again" << endl << endl;
			repeat = true;
		}
	} while (repeat);
}

void View::HeroList()
{
	char input;
	string name;
	int id,hp,dmg;

	cout << controller.GetHeroList();
	bool repeat;
	do {
		repeat = false;
		cout << "1)Add new Hero\n"
			<< "2)Delete Hero\n"
			<< "3)Back\n"
			<< "Choise: ";
		cin >> input;
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
			break;
		case '3':
			break;
		default:
			cout << "Try again" << endl << endl;
			repeat = true;
		}
	} while (repeat);
}

void View::TeamList()
{
	char input;
	string name;
	int playerId[5];


	cout << controller.GetTeamList(); 
	bool repeat;
	do {
		repeat = false;
		cout << "1)Create new Team\n"
			<< "2)Delete Team\n"
			<< "3)Back\n"
			<< "Choice: ";
		cin >> input;
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
			break;
		case '3':
			break;
		default:
			cout << "Try again" << endl << endl;
			repeat = true;
		}
	} while (repeat);
}

void View::SessionList()
{
	char input;
	std::string teamOne, teamTwo;

	cout << controller.GetSessionList();
	bool repeat;
	do {
		repeat = false;
		cout << "\nPlay new Match?(Y/N): ";
		cin >> input;
		if (input == 'y' || input == 'Y')
		{
			cout << "Team One: ";
			cin >> teamOne;
			cout << "Team Two: ";
			cin >> teamTwo;
			if (controller.AddNewSession(teamOne, teamTwo))
				cout << "Failed to find a team";
			SessionList();
		}
		else if (input != 'n' && input != 'N')
		{
			repeat = true;
			cout << "Try again" << endl << endl;
		}
	} while (repeat);

}
