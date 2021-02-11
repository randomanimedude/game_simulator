#pragma once
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <string>
#include "Model.h"


	Player::Player(int Id, std::string Name, int Rank)
	{
		this->Id = Id;
		this->Name = Name;
		this->Rank = Rank;
	}
	Hero::Hero(int Id, std::string Name, int HP, int Damage)
	{
		this->Id = Id;
		this->Name = Name;
		this->HP = HP;
		this->Damage = Damage;
	}
	void Player::ChangeRank(int dif)
	{
		Rank += dif;
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
	void PlayerManager::ChangePlayerRank(int Id, int dif)
	{
		for (Player& player : PlayerList)
			if (player.GetId() == Id)
				player.ChangeRank(dif);
	}
	Player PlayerManager::GetPlayerByName(std::string Name)
	{
		for (Player player : PlayerList)
			if (player.GetName() == Name)
				return player;
		return Player(-1,"error",-1000);
	}
	Player PlayerManager::GetPlayerById(int Id)
	{
		for (Player player : PlayerList)
			if (player.GetId() == Id)
				return player;
		return Player(-1, "error", -1000);
	}
	std::string PlayerManager::ShowPlayerInfo(int Id) const
	{
		for (Player player : PlayerList)
			if (player.GetId() == Id)
				return "|   " + std::to_string(Id) + "\t|   " + player.GetName() + "\t|  " + std::to_string(player.GetRank()) + "\t|";
		return "error";
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
		return Hero(-1,"error",-1000,-1000);
	}
	Hero HeroManager::GetHeroById(int Id)
	{
		for (Hero hero : HeroList)
			if (hero.GetId() == Id)
				return hero;
		return Hero(-1, "error", -1000, -1000);
	}
	std::string HeroManager::ShowHeroInfo(int Id) const
	{
		for (Hero hero : HeroList)
			if (hero.GetId() == Id)
				return "|   " + std::to_string(Id) + "\t|   " + hero.GetName() + "\t|  " + std::to_string(hero.GetHP()) + "\t|  " + std::to_string(hero.GetDamage()) + "\t|";
		return "|\t    No Hero To display\t\t|";
	}

	Team::Team(std::string Name, Player players[])
	{
		this->Name = Name;
		for (int i = 0; i < 5; ++i)
		{	
			this->players[i].player = players[i];
			this->players[i].hero = Hero(-1, "\t-\t", 0, 0);
		}
	}
	void Team::SetPlayerHero(int index, Hero hero)
	{
		players[index].hero = hero;
	}


	void TeamManager::GenerateNewTeam(Team team)
	{
		TeamList.push_back(team);
	}
	void TeamManager::DeleteTeamByName(std::string name)
	{
		for (std::list<Team>::iterator it = TeamList.begin(); it != TeamList.end(); ++it)
			if (it->GetName() == name)
			{
				this->TeamList.erase(it);
				break;
			}
	}
	std::string TeamManager::GetTeamInfo(std::string Name, const PlayerManager* PlayerManager, const HeroManager* HeroManager)
	{
		std::string rez;

		rez = "|\t  Player info  \t\t||\t     Last played hero\t\t|\n";
		for (Team team : TeamList)
			if (team.GetName() == Name)
			{
				rez += "|  Id\t|   Name\t|  Rank\t||  Id\t|  Hero Name\t|  HP\t|  DMG\t|\n";
				rez += "|_______________________________||______________________________________|\n";
				for (int i = 0; i < 5; ++i)
					rez += PlayerManager->ShowPlayerInfo(team.GetPlayer(i).player.GetId()) + HeroManager->ShowHeroInfo(team.GetPlayer(i).hero.GetId()) + '\n';
				break;
			}
		return rez;
	}
	std::string TeamManager::GetTeamInfo(Team team, const PlayerManager* PlayerManager, const HeroManager* HeroManager)
	{
		std::string rez;
		
		rez = "|\t  Player info  \t\t||\t\tHero info\t\t|\n";
		rez += "|  Id\t|   Name\t|  Rank\t||  Id\t|  Hero Name\t|  HP\t|  DMG\t|\n";
		rez += "|_______________________________||______________________________________|\n";
		for (int i = 0; i < 5; ++i)
			rez += PlayerManager->ShowPlayerInfo(team.GetPlayer(i).player.GetId()) + HeroManager->ShowHeroInfo(team.GetPlayer(i).hero.GetId()) + '\n';
		return rez;
	}

	Session::Session(Team* TeamOne, Team* TeamTwo, std::list<Hero> heroList)
	{
		std::vector<Hero> heroVector;			//vector for randomising geroes
		while (!heroList.empty())
		{
			heroVector.push_back(heroList.front());
			heroList.pop_front();
		}

		int t;
		for (int i = 0; i < 5; ++i)						//setting random heroes before session
		{
			t = rand() % heroVector.size();
			TeamOne->SetPlayerHero(i, heroVector[t]);
			heroVector.erase(heroVector.begin() + t);

			t = rand() % heroVector.size();
			TeamTwo->SetPlayerHero(i, heroVector[t]);
			heroVector.erase(heroVector.begin() + t);
		}

		this->TeamOne = *TeamOne;					//copying teams for session history
		this->TeamTwo = *TeamTwo;
	}
	void Session::CalculateWinner(std::string time)
	{
		
		this->StartTime = time;
		int TeamOneHP = 0;
		int TeamTwoHP = 0;
		for (int i = 0; i < 5; ++i)
		{
			TeamOneHP += TeamOne.GetPlayer(i).hero.GetHP() - TeamTwo.GetPlayer(i).hero.GetDamage();
			TeamTwoHP += TeamTwo.GetPlayer(i).hero.GetHP() - TeamOne.GetPlayer(i).hero.GetDamage();
		}
		Winner = (TeamOneHP > TeamTwoHP) ? TeamOne : TeamTwo;
	}
	Team Session::GetTeamOne()
	{
		return TeamOne;
	}
	Team Session::GetTeamTwo()
	{
		return TeamTwo;
	}
	Team Session::GetWinner()
	{
		return Winner;
	}
	std::string Session::GetWinnerInformation()
	{
		return "|\t\t   Team " + Winner.GetName() + " is Victorious!\t\t\t\t|";
	}
	std::string Session::GetSessionInformation()
	{
		return "|    " + StartTime + "\t||\t" + TeamOne.GetName() + " " + ((TeamOne.GetName() == Winner.GetName()) ? "(win)" : "(lose)") + " vs " + TeamTwo.GetName() + " " + ((TeamTwo.GetName() == Winner.GetName()) ? "(win)" : "(lose)")+"\t|";
	}


	GameManager::GameManager(HeroManager& heroManager, PlayerManager& playerManager)
	{
		this->heroManager = &heroManager;
		this->playerManager = &playerManager;
	}
	void GameManager::PerformGameSession(Team *TeamOne, Team *TeamTwo)
	{
		time_t result = time(NULL);			//some time-to-string cheats
		char str[26];
		ctime_s(str, sizeof str, &result);
		std::string timeRez = str;
		timeRez = timeRez.substr(0, 24);

		GameSessions.push_back(Session(TeamOne, TeamTwo, heroManager->GetHeroList()));
		GameSessions.back().CalculateWinner(timeRez);
		if (GameSessions.back().GetTeamOne().GetName() != GameSessions.back().GetWinner().GetName())
			for (int i = 0; i < 5; ++i)
				playerManager->ChangePlayerRank(GameSessions.back().GetTeamOne().GetPlayer(i).player.GetId(), -25);
		else 
			for (int i = 0; i < 5; ++i)
				playerManager->ChangePlayerRank(GameSessions.back().GetTeamTwo().GetPlayer(i).player.GetId(), -25);
		for (int i = 0; i < 5; ++i)
			playerManager->ChangePlayerRank(GameSessions.back().GetWinner().GetPlayer(i).player.GetId(), 25);
	}


