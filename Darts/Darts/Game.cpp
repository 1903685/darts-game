#include <iostream>
#include "Game.h"

Game::Game()
{
	std::cout << "Game constructor called\n";
}


Game::~Game()
{
	std::cout << "Game destructor called!\n";
	delete _pBoard;
	delete _pOne;
	delete _pTwo;
}

void Game::Play()
{
	std::cout << _pOne->GetName() << std::endl;;

	_pOne->NineDartFinish1(*_pBoard);
	std::cout << std::endl;
	_pTwo->NineDartFinish2(*_pBoard);
}


void Game::PlayAdvancedStrategy()
{
	while (_pOne->CheckWin() != true && _pTwo->CheckWin() != true)
	{
//		if (NineDartFinish) 
//		{
//			{ //Both players aim to score 180 
//				_pOne->AimTon80(*_pBoard); //Player One throws 3 times
//				_pTwo->AimTon80(*_pBoard); //Player Two throws 3 times
//			}
//			{ //Both players aim to score 180 
//				_pOne->AimTon80(*_pBoard); //Player One throws 3 times
//				_pTwo->AimTon80(*_pBoard); //Player Two throws 3 times
//			}
//			{ //Player One tries to finish the game
//				_pOne->AimCheckout141(*_pBoard); //Player One throws 3 times
//				if (_pOne->CheckWin()) //if score is 0 end the game
//				{
//					break;
//				}
//			}
//			{ //Player Two tries to finish the game
//				_pTwo->AimCheckout141(*_pBoard); //Player Two throws 3 times
//				if (_pTwo->CheckWin()) //if score is 0 end the game
//				{
//					break;
//				}
//			}
//			NineDartFinish = false;
//		}

//		_pOne->ThrowDouble(CheckWinningPosition(_pOne, _pBoard), *_pBoard);
		//Player One Turn
//		Throw3Darts(_pOne, _pBoard);
		//////Player Two Turn
//		Throw3Darts(_pTwo, _pBoard);
        _pOne->ThrowDouble(0, *_pBoard);
	}

	DisplayWinner(_pOne, _pTwo);
}

void Game::Throw3Darts(Player* player, Board* board) 
{
	player->ThrowDouble(CheckWinningPosition(player, board), *board);
	player->ThrowDouble(CheckWinningPosition(player, board), *board);
	player->ThrowDouble(CheckWinningPosition(player, board), *board);
}

int16_t Game::CheckWinningPosition(Player* player, Board* board)
{
	for (int8_t i = 0; i < X; ++i) 
	{
		for (int8_t j = 0; j < Y; ++j)
		{
			if (player->GetScore() - board->GetAtPosition(i, j) * 2 == 0) { //check if hitting double will end the game
				return board->GetAtPosition(i, j);
			}
			else if ((player->GetScore()) - BULL == 0) { //check if hitting the bull will end the game
				return BULL;
			}
			else if (player->IsEven(player->GetScore() - board->GetAtPosition(i, j) >= 2) &&
                     player->GetScore() - board->GetAtPosition(i, j) != 0 ) { //otherwise aim to not bust, to get even score and still be able to win (the smallest score like this is 2)
                player->ThrowSingle(board->GetAtPosition(i, j), *board);
            }
		}
	}
    return random()%20 + 1;
}

void Game::DisplayWinner(Player* playerOne, Player* playerTwo)
{
	if (playerOne->CheckWin()) {
		std::cout << "Player One wins!\n";
	}
	else if (playerTwo->CheckWin()) {
		std::cout << "Player Two wins!\n";
	}		
}

////When score is 50
//if (_pOne->GetScore() == 50)  //Player One 1st Shot
//{
//	_pOne->ThrowBull(90, *_pBoard);
//	if (CheckWin(_pOne))
//	{
//		PlayerOneWins = true;
//		break;
//	}
//}