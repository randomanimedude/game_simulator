#pragma once
#include "Controller.h"
#include <string>

Controller::Controller(PlayerManager &playerManager, HeroManager &heroManager, TeamManager &teamManager, GameManager &gameManager)
{
	this->playerManager = &playerManager;
	this->heroManager = &heroManager;
	this->teamManager = &teamManager;
	this->gameManager = &gameManager;
}

std::string Controller::GetPlayerList()
{
	std::string rez="\n _______________________________\n|  Id\t|   Name\t| Rank\t|\n|_______________________________|\n";
	for (auto player : playerManager->GetPlayerList())
		rez += playerManager->ShowPlayerInfo(player.GetId()) + '\n';
	rez += "|_______________________________|\n";
	if (playerManager->GetPlayerList().empty())
		rez = "\nPlayer list is empty!\n\n";
	return rez;
}

std::string Controller::GetHeroList()
{
	std::string rez = "\n _______________________________________\n|  Id\t|   Name\t|  HP\t|  DMG\t|\n|_______________________________________|\n";
	for (auto hero : heroManager->GetHeroList())
		rez += heroManager->ShowHeroInfo(hero.GetId()) + '\n';
	rez += "|_______________________________________|\n";
	if (heroManager->GetHeroList().empty())
		rez = "\nHero list is empty!\n\n";
	return rez;
}

std::string Controller::GetTeamList()
{
	std::string rez = "\n";
	std::string line = "_______________________________________________________________________";
	for (Team team : *(teamManager->GetTeamList()))
	{		
		rez += " " + line + "\n|  \t\t\tTeam\t  " + team.GetName() +"\t\t\t\t|\n|" + line + "|\n" + teamManager->GetTeamInfo(team.GetName(), playerManager, heroManager) + "|" + line + "|\n";
	}
	if (teamManager->GetTeamList()->empty())
		rez = "\nTeam list is empty!\n\n";
	return rez;
}

std::string Controller::GetSessionList()
{
	std::string line = "_______________________________________________________________________";
	std::string rez = "";
	for (Session session : gameManager->GetGameSessions())
	{
		rez += "\n " + line + "\n";
		rez += session.GetSessionInformation() + "\n";
		rez += "|" + line + "|" + "\n|  \t\t\tTeam\t  " + session.GetTeamOne().GetName() + "\t\t\t\t|\n|" + line + "|\n";
		rez += teamManager->GetTeamInfo(session.GetTeamOne(), playerManager, heroManager);
		rez += "|" + line + "|" + "\n|  \t\t\tTeam\t  " + session.GetTeamTwo().GetName() + "\t\t\t\t|\n|" + line + "|\n";
		rez += teamManager->GetTeamInfo(session.GetTeamTwo(), playerManager, heroManager);
		rez += "|" + line + "|\n" + session.GetWinnerInformation() + "\n|" + line + "|\n\n";
	}
	if (gameManager->GetGameSessions().empty())
		rez = "\nNo games to display\n";
	return rez;
}

void Controller::AddNewPlayer(int Id, std::string Name)
{
	playerManager->CreatePlayer(Id, Name, 1200);   ///1200 -- default rank
}

void Controller::AddNewHero(int Id, std::string Name, int HP, int DMG)
{
	heroManager->CreateHero(Id, Name, HP, DMG);
}

void Controller::AddNewTeam(std::string Name, int PlayerId[])
{
	Player newTeamPlayers[5];
	for (int i = 0; i < 5; ++i)
	{
		newTeamPlayers[i] = playerManager->GetPlayerById(PlayerId[i]);
	}
	teamManager->GenerateNewTeam(Team(Name, newTeamPlayers));
}

bool Controller::AddNewSession(std::string teamOne, std::string teamTwo)
{
	int counter = 0;

	Team* team1, * team2 = team1 = new Team;							//searching for teams by name
	for(Team &team: *(teamManager->GetTeamList()))
	{
		if (team.GetName() == teamOne)
		{
			team1 = &team;
			++counter;
		}
		if (team.GetName() == teamTwo)
		{
			team2 = &team;
			++counter;
		}
	}
	if (counter == 2)
	{
		gameManager->PerformGameSession(team1, team2);
		return false;
	}
	delete team1;
	delete team2;
	return true;

}

void Controller::DeletePlayer(int Id)
{
	playerManager->DeletePlayer(Id);
	for (Team team : *(teamManager->GetTeamList()))
		for (int i = 0; i < 5; ++i)
			if (team.GetPlayer(i).player.GetId() == Id)
				teamManager->DeleteTeamByName(team.GetName());			//delete team if player of this team is deleted
}

void Controller::DeleteHero(int Id)
{
	heroManager->DeleteHero(Id);
}

void Controller::DeleteTeam(std::string name)
{
	teamManager->DeleteTeamByName(name);
}