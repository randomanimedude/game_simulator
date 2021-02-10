#include <iostream>
#include <string>
#include "View.h"
#include <ctime>


using namespace std;

int main()
{
	srand(time(NULL));

	PlayerManager playerManager;
	playerManager.CreatePlayer(1, "anime", 1200);
	playerManager.CreatePlayer(2, "plr1", 1200);
	playerManager.CreatePlayer(3, "plr2", 1200);
	playerManager.CreatePlayer(4, "duuuude", 1200);
	playerManager.CreatePlayer(5, "bahamut", 1200);
	playerManager.CreatePlayer(6, "faker", 1200);
	playerManager.CreatePlayer(7, "gambler", 1200);
	playerManager.CreatePlayer(8, "miner", 1200);
	playerManager.CreatePlayer(9, "n@g1b@t0r", 1200);
	playerManager.CreatePlayer(10, "pro100pr0", 1200);
	HeroManager heroManager;
	heroManager.CreateHero(1, "manki", 150, 140);
	heroManager.CreateHero(2, "knight", 140, 150);
	heroManager.CreateHero(3, "marine", 80, 300);
	heroManager.CreateHero(4, "swarm", 145, 110);
	heroManager.CreateHero(5, "beebee", 155, 145);
	heroManager.CreateHero(6, "kirra", 120, 120);
	heroManager.CreateHero(7, "zeratull", 155, 145);
	heroManager.CreateHero(8, "kerrigan", 120, 120);
	heroManager.CreateHero(9, "raven", 155, 145);
	heroManager.CreateHero(10, "imouto", 120, 120);
	TeamManager teamManager;
	Player tempPlayerArr[] = { playerManager.GetPlayerById(1),
								playerManager.GetPlayerById(3),
								playerManager.GetPlayerById(5),
								playerManager.GetPlayerById(7),
								playerManager.GetPlayerById(9)};
	teamManager.GenerateNewTeam(Team("amerika", tempPlayerArr, heroManager.GetHeroList()));
	tempPlayerArr[0] = playerManager.GetPlayerById(2);
	tempPlayerArr[1] = playerManager.GetPlayerById(4);
	tempPlayerArr[2] = playerManager.GetPlayerById(6);
	tempPlayerArr[3] = playerManager.GetPlayerById(8);
	tempPlayerArr[4] = playerManager.GetPlayerById(10);
	teamManager.GenerateNewTeam(Team("anglia", tempPlayerArr, heroManager.GetHeroList()));
	GameManager gameManager;
	Controller controller(playerManager,heroManager,teamManager,gameManager);
	View view(controller);

	while (1)
	{
		view.MainMenu();
	}
}
