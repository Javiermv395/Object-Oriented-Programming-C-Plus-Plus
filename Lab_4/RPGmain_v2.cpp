#include <iostream>
#include <string>
#include "RPG.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    RPG player1 = RPG("Player1", 70, 15, 45, "mage");
    RPG player2 = RPG("player2", 70, 15, 45, "mage");

    RPG game;

    game.gameLoop(&player1, &player2);
    game.displayEnd(player1, player2);
}
