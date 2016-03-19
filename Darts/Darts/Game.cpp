#include <iostream>
#include "Game.h"

Game::Game()
{
	_player1.SetName("Player 1");
	_player2.SetName("Player 2");
	_board1.Populate();
	_board2.Populate();
}


Game::~Game()
{}

void Game::Play(Board &Board1, Board &Board2)
{
	_player1.SetName("Player 1");
	_player2.SetName("Player 2");
	
	_player1.ThrowBull(100, Board1);
	_player1.ThrowTriple(20, Board1);
	_player1.ThrowTriple(20, Board1);
	_player1.ThrowTriple(20, Board1);
	_player1.ThrowTriple(20, Board1);
	_player1.ThrowTriple(20, Board1);
	_player1.ThrowTriple(20, Board1);
	_player1.ThrowTriple(20, Board1);

	Board1.DisplayScore();
	uint16_t score = *(Board1.GetScore());
	std::cout << score;
}