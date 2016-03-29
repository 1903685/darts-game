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

	uint8_t _choice = 0;
	bool _fail = false;
	bool _nineDartFinish = true;

	uint16_t _newScore = 501;
	int16_t _temp = 0;
	int16_t _simulateCounter = 0;
	int16_t _player1WinCounter = 0;
	int16_t _player2WinCounter = 0;

	int16_t CheckWinningPosition(Player* player, Board* board);
	void CheckBusted(Player* player, uint16_t temp);
	void DisplayWinner(Player* playerOne, Player* playerTwo);
	void Throw3Darts(Player* player, Board* board);

	void PlayNineDartFinish1();
	//void NineDartFinish2(Board& board);

	void DisplayInstructions();
};

#endif