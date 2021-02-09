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
	std::string rez=" _______________________________________\n|  Id\t|   Name\t|   Rank\t|\n|_______________________________________|\n";
	for (auto player : playerManager->GetPlayerList())
		rez += playerManager->ShowPlayerInfo(player.GetId()) + '\n';
	rez += "|_______________________________________|\n";
	return rez;
}

std::string Controller::GetHeroList()
{
	std::string rez = " _______________________________________\n|  Id\t|   Name\t|  HP\t|  DMG\t|\n|_______________________________________|\n";
	for (auto hero : heroManager->GetHeroList())
		rez += heroManager->ShowHeroInfo(hero.GetId()) + '\n';
	rez += "|_______________________________________|\n";
	return rez;
}

std::string Controller::GetTeamList()
{
	return " ";
}

std::string Controller::GetSessionList()
{
	return " ";
}

void Controller::AddNewPlayer()
{

}

void Controller::AddNewHero()
{

}

void Controller::AddNewTeam()
{

}

void Controller::AddNewSession()
{

}

void Controller::DeletePlayer()
{

}

void Controller::DeleteHero()
{

}

void Controller::DeleteTeam()
{

}