#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
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

	void Play(Board &Board1); //Plays the game of darts

private:
	Board _board;
	Player _one;
	Player _two;
};

#endif GAME_H

