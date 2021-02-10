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
	void AddNewPlayer(int, std::string);
	void AddNewHero(int, std::string, int, int);
	void AddNewTeam(std::string, int[]);
	void AddNewSession();
	void DeletePlayer(int);
	void DeleteHero(int);
	void DeleteTeam(std::string);

private:
	PlayerManager *playerManager;
	HeroManager *heroManager;
	TeamManager *teamManager;
	GameManager *gameManager;
};
