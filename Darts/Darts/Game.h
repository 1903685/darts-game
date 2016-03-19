#pragma once
#ifndef GAME_H
#define GAME_H

#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"
class Board;
class GenericPlayer;
class Player;

class Game
{
public:
	Game();
	~Game();

	void Play(Board &Board1, Board &Board2); //Plays the game of darts

private:
	Board _board1;
	Board _board2;

	Player _player1;
	Player _player2;
};

#endif GAME_H

