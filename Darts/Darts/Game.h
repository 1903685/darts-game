#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Play(); //Plays the game of darts
	void PlayAdvancedStrategy();

private:
	Board *_pBoard = new Board;
	Player *_pOne = new Player(501, "George");
	Player *_pTwo = new Player(501, "Matt");

	int16_t CheckWinningPosition(Player* player, Board* board);
	void DisplayWinner(Player* playerOne, Player* playerTwo);
	void Throw3Darts(Player* player, Board* board);
	bool PlayerOneWins = false;
	bool PlayerTwoWins = false;
	bool NineDartFinish = true;
};

#endif

