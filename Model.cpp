#pragma once
#include <string>
#include <list>
#include "Model.h"


	Player::Player(int Id, std::string Name, int Rank)
	{
		this->Id = Id;
		this->Name = Name;
		this->Rank = Rank;
	}
	void Player::ChangeRank(int dif) 
	{ 
		Rank += dif; 
	}

	Hero::Hero(int Id, std::string Name, int HP, int Damage)
	{
		this->Id = Id;
		this->Name = Name;
		this->HP = HP;
		this->Damage = Damage;
	}

	void PlayerManager::CreatePlayer(Player player)
	{
		this->PlayerList.push_back(player);
	}
	void PlayerManager::CreatePlayer(int Id, std::string Name, int Rank = 0)
	{
		this->PlayerList.push_back(Player(Id, Name, Rank));
	}
	void PlayerManager::DeletePlayer(int Id)
	{
		for (std::list<Player>::iterator it = PlayerList.begin(); it != PlayerList.end(); ++it)
			if (it->GetId() == Id)
			{
				PlayerList.erase(it);
				break;
			}
	}
	Player PlayerManager::GetPlayerByName(std::string Name)
	{
		for (Player player : PlayerList)
			if (player.GetName() == Name)
				return player;
	}
	Player PlayerManager::GetPlayerById(int Id)
	{
		for (Player player : PlayerList)
			if (player.GetId() == Id)
				return player;
	}
	std::string PlayerManager::ShowPlayerInfo(int Id) const
	{
		for (Player player : PlayerList)
			if (player.GetId() == Id)
				return "|   " + std::to_string(Id) + "\t|   " + player.GetName() + "\t|   " + std::to_string(player.GetRank()) + "\t|";
	}

	void HeroManager::CreateHero(Hero hero)
	{
		this->HeroList.push_back(hero);
	}
	void HeroManager::CreateHero(int Id, std::string Name, int HP, int Damage)
	{
		this->HeroList.push_back(Hero(Id, Name, HP, Damage));
	}
	void HeroManager::DeleteHero(int Id)
	{
		for (std::list<Hero>::iterator it = HeroList.begin(); it != HeroList.end(); ++it)
			if (it->GetId() == Id)
			{
				HeroList.erase(it);
				break;
			}
	}
	Hero HeroManager::GetHeroByName(std::string Name)
	{
		for (Hero hero : HeroList)
			if (hero.GetName() == Name)
				return hero;
	}
	Hero HeroManager::GetHeroById(int Id)
	{
		for (Hero hero : HeroList)
			if (hero.GetId() == Id)
				return hero;
	}
	std::string HeroManager::ShowHeroInfo(int Id) const
	{
		for (Hero hero : HeroList)
			if (hero.GetId() == Id)
				return "|   " + std::to_string(Id) + "\t|   " + hero.GetName() + "\t|   " + std::to_string(hero.GetHP()) + "\t|   " + std::to_string(hero.GetDamage()) + "\t|";
	}

	Team::Team(std::string Name, TeamPlayer players[])
	{
		this->Name = Name;
		for (int i = 0; i < 5; ++i)
			this->players[i] = players[i];
	}

	void TeamManager::GenerateNewTeam(Team team)
	{
		TeamList.push_back(team);
	}
	std::string TeamManager::GetTeamInfo(std::string Name, const PlayerManager& PlayerManager, const HeroManager& HeroManager)
	{
		std::string rez;
		for (Team team : TeamList)
			if (team.GetName() == Name)
			{
				rez = "|\t\t\t\t\t\t\t" + Name + "\t\t\t\t\t|\n";
				for (int i = 0; i < 5; ++i)
					rez += PlayerManager.ShowPlayerInfo(team.GetPlayer(i).player->GetId()) + HeroManager.ShowHeroInfo(team.GetPlayer(i).hero->GetId()) + '\n';
				break;
			}
		return rez;
	}

	Session::Session(const Team& TeamOne, const Team& TeamTwo)
	{
		this->TeamOne = &TeamOne;
		this->TeamTwo = &TeamTwo;
	}
	void Session::CalculateWinner()
	{
		int TeamOneHP = 0;
		int TeamTwoHP = 0;
		for (int i = 0; i < 5; ++i)
		{
			TeamOneHP += TeamOne->GetPlayer(i).hero->GetHP() - TeamTwo->GetPlayer(i).hero->GetDamage();
			TeamTwoHP += TeamTwo->GetPlayer(i).hero->GetHP() - TeamOne->GetPlayer(i).hero->GetDamage();
		}
		Winner = (TeamOneHP > TeamTwoHP) ? TeamOne : TeamTwo;
	}
	std::string Session::GetWinnerInformation()
	{
		return "|\t\t\t\tTeam " + Winner->GetName() + " is Victorious!\t\t\t\t|";
	}
	std::string Session::GetSessionInformation()
	{
		return "|\t" + StartTime + "\t|\t" + TeamOne->GetName() + " " + ((TeamOne == Winner) ? "(win)" : "(lose)") + " vs " + TeamTwo->GetName() + " " + ((TeamTwo == Winner) ? "(win)" : "(lose)")+"\t|";
	}

	void GameManager::PerformGameSession(const Team& TeamOne, const Team& TeamTwo)
	{
		GameSessions.push_back(Session(TeamOne, TeamTwo));
		GameSessions.back().CalculateWinner();
	}


