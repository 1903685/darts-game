#include <iostream>
#include "Game.h"

Game::Game()
{
	_one.SetName("George");
}


Game::~Game()
{}

void Game::Play(Board &Board)
{
	std::cout << _one.GetName() << std::endl;;
	std::cout << _one.GetScore() << std::endl;

	_one.NineDartFinish1(Board);
	std::cout << std::endl;
	_two.NineDartFinish2(Board);
}