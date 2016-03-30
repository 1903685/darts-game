#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

    void Play(const std::vector<GenericPlayer*>& players); //Plays the game of darts
private:
    Board *_pBoard = new Board;
    GenericPlayer* GetCurrentPlayer();
    GenericPlayer* NextPlayer();
//	uint8_t _choice = 0;
//	bool _fail = false;
	uint16_t _newScore = 501;
	int16_t _temp = 0;
	int16_t _simulateCounter = 0;
    
    void DisplayEndGame(std::size_t winnerIndex);

	int16_t CheckWinningPosition(GenericPlayer* player, Board* board);
	void CheckBusted(GenericPlayer* player, uint16_t temp);
	void DisplayWinner(GenericPlayer* playerOne, GenericPlayer* playerTwo);
	void Throw3Darts(GenericPlayer* player, Board* board);
    GenericPlayer* WhoFirst();

	void PlayNineDartFinish();

	void DisplayInstructions();
    
    std::size_t _currentPlayer;
    std::vector<GenericPlayer*> _players;
    
};

#endif