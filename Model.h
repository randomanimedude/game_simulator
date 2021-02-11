#pragma once
#include <string>
#include <list>

class Player
{
public:
	Player() {};
	Player(int, std::string, int);

	void ChangeRank(int);

	int GetId() const { return Id; }
	int GetRank() const { return Rank; }

	std::string GetName() { return Name; }

private:
	int Id;
	std::string Name;
	int Rank;
};

class Hero
{
public:
	Hero() {};
	Hero(int, std::string, int, int);
	
	int GetId() const { return Id; }
	int GetHP() const { return HP; }
	int GetDamage() const { return Damage; }

	std::string GetName() { return Name; }
	
private:
	int Id;
	std::string Name;
	int HP;
	int Damage;
};

class PlayerManager
{
public:
	void CreatePlayer(Player);
	void CreatePlayer(int, std::string, int);
	void DeletePlayer(int);

	std::list<Player> GetPlayerList() { return PlayerList; }

	Player GetPlayerByName(std::string);
	Player GetPlayerById(int);

	std::string ShowPlayerInfo(int) const;

private:
	std::list<Player> PlayerList;
};

class HeroManager
{
public:
	void CreateHero(Hero);
	void CreateHero(int, std::string, int, int);
	void DeleteHero(int);

	std::list<Hero> GetHeroList() { return HeroList; }

	Hero GetHeroByName(std::string);
	Hero GetHeroById(int);

	std::string ShowHeroInfo(int) const;

private:
	std::list<Hero> HeroList;
};

struct TeamPlayer
{
	TeamPlayer() {};

	Hero hero;
	Player player;
};
class Team
{
public:
	Team() {};
	Team(std::string, Player[]);

	void SetPlayerHero(int, Hero);

	std::string GetName() const { return Name; }

	TeamPlayer GetPlayer(int index) const { return players[index]; }

private:
	std::string Name;
	TeamPlayer players[5];

};

class TeamManager
{
public:
	TeamManager() {};
	void GenerateNewTeam(Team);
	void DeleteTeamByName(std::string);
	std::string GetTeamInfo(std::string, const PlayerManager*, const HeroManager*);
	std::string GetTeamInfo(Team, const PlayerManager*, const HeroManager*);
	std::list<Team>* GetTeamList() { return &TeamList; };

private:
	std::list<Team> TeamList;
};

class Session
{
public:
	Session() {};
	Session(Team*, Team*, std::list<Hero>);

	void CalculateWinner(std::string time);

	Team GetTeamOne();
	Team GetTeamTwo();
	std::string GetWinnerInformation();
	std::string GetSessionInformation();

private:
	std::string StartTime;
	Team TeamOne;
	Team TeamTwo;
	Team Winner;

};

class GameManager
{
public:
	GameManager(HeroManager&);

	void PerformGameSession(Team*, Team*);
	std::list<Session> GetGameSessions() { return GameSessions; }

private:
	HeroManager* heroManager;
	std::list<Session> GameSessions;

};