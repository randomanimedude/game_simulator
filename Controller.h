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
	void AddNewPlayer();
	void AddNewHero();
	void AddNewTeam();
	void AddNewSession();
	void DeletePlayer();
	void DeleteHero();
	void DeleteTeam();

private:
	PlayerManager *playerManager;
	HeroManager *heroManager;
	TeamManager *teamManager;
	GameManager *gameManager;
};
