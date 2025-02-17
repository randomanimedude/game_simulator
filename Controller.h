#pragma once
#include "Model.h"

class Controller
{
public:
	Controller() {};
	Controller(PlayerManager&, HeroManager&, TeamManager&, GameManager&);
	std::string GetPlayerList();
	std::string GetHeroList();
	std::string GetTeamList();
	std::string GetSessionList();
	int GetNumberOfHeroes() { return heroManager->GetHeroList().size(); }
	bool AddNewSession(std::string, std::string);
	void AddNewPlayer(int, std::string);
	void AddNewHero(int, std::string, int, int);
	void AddNewTeam(std::string, int[]);
	void DeletePlayer(int);
	void DeleteHero(int);
	void DeleteTeam(std::string);

private:
	PlayerManager *playerManager;
	HeroManager *heroManager;
	TeamManager *teamManager;
	GameManager *gameManager;
};
