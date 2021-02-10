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
	Team(std::string, Player[], std::list<Hero>);

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
	std::string GetTeamInfo(std::string Name, const PlayerManager& PlayerManager, const HeroManager& HeroManager);
	std::list<Team> GetTeamList() { return TeamList; };

private:
	std::list<Team> TeamList;
	PlayerManager* playerManager;
};

class Session
{
public:
	Session(const Team&, const Team&);

	void CalculateWinner();

	std::string GetWinnerInformation();
	std::string GetSessionInformation();

private:
	std::string StartTime;
	const Team* TeamOne;
	const Team* TeamTwo;
	const Team* Winner;

};

class GameManager
{
public:
	void PerformGameSession(const Team&, const Team&);

private:
	std::list<Session> GameSessions;

};