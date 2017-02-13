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

    void Play(); //Plays the game of darts
private:
    std::size_t _currentPlayer;
    std::vector<GenericPlayer*> _players; //vector of pointers to GenericPlayer
    Board *_pBoard = new Board;
    GenericPlayer* NextPlayer();
    GenericPlayer* WhoFirst();
    
    void PushNames(uint16_t numPlayers);
    uint16_t SetNumPlayers();
        
	int16_t CheckWinningPosition(GenericPlayer* player, Board* board);
    void PlayNineDartFinish(const std::vector<GenericPlayer*>& players);
    void Throw3Darts(GenericPlayer* player, Board* board);
    void CheckBusted(GenericPlayer* player, uint16_t temp);
    void DisplayEndGame(std::size_t winnerIndex);
    
	void DisplayInstructions();
    
	int _choice;
    uint16_t _newScore;
    int16_t _temp;
    int16_t _simulateCounter;
    std::vector<std::string> _names;
};
#endif