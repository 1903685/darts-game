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
	/*std::cout << _pOne->GetName() << std::endl;;

	_pOne->NineDartFinish1(*_pBoard);
	std::cout << std::endl;
	_pTwo->NineDartFinish2(*_pBoard);*/
	
	//std::cout << "Hello Fella! You are about to simulate exciting game of Darts 501!\n";
	//std::cout << "How many times you want to simulate? ";
	//std::cout << "Choose strategy:\n";
	//std::cout << "1 - Cheek Strategy\n";
	std::cout << "How many times you want to play? ";
	std::cin >> _simulateCounter;
	std::cout << std::endl;

	for (int i = 0; i < _simulateCounter; ++i)
	{
//		uint8_t r = rand() % 2; //used to randomize strategy
        PlayAdvancedStrategy();
//		switch (r) {
//		case 0:
//			PlayAdvancedStrategy();
//			break;
//		case 1:
//			PlayNineDartFinish1();
//			break;
//		}
		
	}
	std::cin.get();
}

//do {
//	std::cin >> _simulateCounter;
//	std::cout << std::endl;
//	_fail = std::cin.fail();
//
//	std::cin.clear();
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//} while (_fail);

void Game::PlayAdvancedStrategy()
{
	_pOne->SetScore(_newScore);
	_pTwo->SetScore(_newScore);

	do
	{
		////////Player One Turn
		Throw3Darts(_pOne, _pBoard);
		////////Player Two Turn 
		Throw3Darts(_pTwo, _pBoard);
	} while (_pOne->CheckWin() != true && _pTwo->CheckWin() != true);

	DisplayWinner(_pOne, _pTwo);
}

void Game::PlayNineDartFinish1()
{
	_pOne->SetScore(_newScore);
	_pTwo->SetScore(_newScore);

	do
	{
		////////Player One Turn
		Throw3Darts(_pOne, _pBoard);
		////////Player Two Turn
		Throw3Darts(_pTwo, _pBoard);
	} while (_pOne->CheckWin() != true && _pTwo->CheckWin() != true);

	DisplayWinner(_pOne, _pTwo);
}

void Game::Throw3Darts(Player* player, Board* board) 
{
	uint16_t _temp = player->GetScore();
	CheckWinningPosition(player, board);
	CheckBusted(player, _temp);
	CheckWinningPosition(player, board);
	CheckBusted(player, _temp);
	CheckWinningPosition(player, board);
	CheckBusted(player, _temp);
}

int16_t Game::CheckWinningPosition(Player* player, Board* board) //Playing Nine Dart Finish Strategy
{
	for (uint8_t i = 1; i >= 0; --i) //loop used to iterate through board
	{
		for (uint8_t j = 20; j >= 0; --j) //Choose the highest possible number to aim for and still be able to win
		{
            
			if (player->GetScore() - board->GetAtPosition(i, j) * 2 == 0) { //check if hitting double will end the game
                player->ThrowDouble(board->GetAtPosition(i, j), board);
                return 0;
			}
			else if ((player->GetScore()) - BULL == 0) { //check if hitting the bull will end the game
                player->ThrowBull();
                return 0;
			}
            else if ( (player->GetScore() - j * 3) >= 2 ) { //check if scoring a triple will leave at least the smallest possible winning score which is 2
                player->ThrowTriple(j, board);
                return 0;
            }
            else if ( (player->GetScore() - j * 2) >= 2 ) { //check if scoring a double will leave at least the smallest possible winning score which is 2
                player->ThrowDouble(j, board); //A value of 20-0 will be used to throw a double
                return 0;
            }
            else if ( ( (player->GetScore() - j) >= 2 ) && ( player->IsOdd(j) ) ) { //check if scoring a single will leave at least the smallest possible winning score and if aim is an odd number
                player->ThrowSingle(j, board); //If score is not even (odd) then throw a single.
                return 0;
            }
        }
	}
    return 0;
}
//	if (player->IsEven(player->GetScore())) //Check if the score is even
//	{
//		for (uint8_t i = 20; i >= 0; --i) //Choose the highest possible number to aim for and still be able to win
//		{
//			if ((player->GetScore() - (i * 2)) >= 2) { //Check if scoring a double will leave at least the smallest possible winning score
//				return i; //A value of 0-20 will be used to throw a double
//			}
//		}
//	}
//	else {
//		{
//			if ((player->GetScore() - i) >= 2 && player->IsOdd(i) ) { //Check if scoring a single will leave at least the smallest possible winning score and if aim is an odd number
//				player->ThrowSingle(i, *board); //Throw single and aim an odd number to get an even score (odd - odd = even, e.x. 7 - 3 = 4)
//				return 0; //to end the function the value of 0 will be used to throw a double after throwing a single but it doesnt make any diffrence in simulation
//			}
//		}
//	}
//		for (uint8_t i = 20; i >= 0; --i) //If score is not even (odd) then throw single.

void Game::CheckBusted(Player* player, uint16_t temp)
{
    if (player->GetScore() < 0 || player->GetScore() == 1) //Busted if score is smaller then 0 or equal to 1
    {
        player->SetScore(temp);
    }
}

void Game::DisplayWinner(Player* playerOne, Player* playerTwo)
{
    if (playerOne->CheckWin()) {
        _player1WinCounter++;
        if (_player1WinCounter == 1) {
            std::cout << "Player One wins! He has won " << _player1WinCounter << " time!\n";
            std::cout << "Player Two has won " << _player2WinCounter << " times!\n";
        }
        else {
            std::cout << "Player One wins! He has won " << _player1WinCounter << " times!\n";
            std::cout << "Player Two has won " << _player2WinCounter << " times!\n";
        }
    }
    else if (playerTwo->CheckWin()) {
        _player2WinCounter++;
        if (_player2WinCounter == 1) {
            std::cout << "Player Two wins! He has won " << _player2WinCounter << " time!\n";
            std::cout << "Player One has won " << _player1WinCounter << " times!\n";
        }
        else {
            std::cout << "Player Two wins! He has won " << _player2WinCounter << " times!\n";
            std::cout << "Player One has won " << _player1WinCounter << " times!\n";
        }
    }
    else {
        std::cout << "Nobody has won!";
    }
}

void Game::DisplayInstructions()
{
    std::cout << "Hello Fella! You are about to simulate or play exciting game of Darts 501!\n";
    std::cout << "Choose strategy:\n";
    std::cout << "1 - Cheek Strategy\n";
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

//if (player->IsEven(player->GetScore()))
//{
//	for (int i = 20; i >= 0; --i)
//	{
//		if ((player->GetScore() - (i * 2)) >= 2) {
//			//player->ThrowSingle(i, *board);
//			return i;
//		}
//	}
//}
//else {
//	for (int i = 20; i >= 0; --i)
//	{
//		if ((player->GetScore() - i) >= 2) {
//			player->ThrowSingle(i, *board);
//			return 0;
//		}
//	}
//}
//if (player->IsEven(player->GetScore()))
//{
//	for (int i = 20; i >= 0; --i)
//	{
//		if ((player->GetScore() - (i * 2)) >= 2) {
//			//player->ThrowSingle(i, *board);
//			return i;
//		}
//		else if ((player->GetScore() - i) >= 2) {
//			player->ThrowSingle(i, *board);
//			return 0;
//		}
//	}
//}
//else if (player->IsEven(player->GetScore() - board->GetAtPosition(i, j)) >= 2) { //otherwise aim to not bust, to get even score and still be able to win (the smallest score like this is 2)
//	player->ThrowSingle(board->GetAtPosition(i, j), *board);
//	return 0;
//if score is even 
//else if (player->IsEven(player->GetScore())) {

//}

//aim for even

//if score is odd
//aim for odd
//}
/*else if (player->IsEven(player->GetScore()))
{
if ((player->GetScore() - (j * 2)) >= 2) {
return j;
}
else if ((player->GetScore() - j) >= 2) {
player->ThrowSingle(j, *board);

}
}*/