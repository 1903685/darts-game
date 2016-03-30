#include <iostream>
#include "Game.h"

Game::Game() : _players(0), _currentPlayer(0)
{
	std::cout << "Game constructor called\n";
}


Game::~Game()
{
	std::cout << "Game destructor called!\n";
	delete _pBoard;
    _pBoard = nullptr;
}

void Game::Play(const std::vector<GenericPlayer*>& players)
{
    _currentPlayer = 0;
    
    for(auto* p : _players) {
        delete p;
    }
    _players.clear();
    
    _players = players;
    _currentPlayer = 0;

	std::cout << "How many times you want to play? ";
	std::cin >> _simulateCounter;
	std::cout << std::endl;

	for (int i = 0; i < _simulateCounter; ++i)
	{
			PlayNineDartFinish();
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

void Game::PlayNineDartFinish()
{
	/*_pOne->SetScore(_newScore);
	_pTwo->SetScore(_newScore);

    _pOne = WhoFirst(_pOne, _pTwo);
    _pTwo = Oponent(_pOne, _pTwo);
    */
    for(auto p : _players) {
        p->SetScore(_newScore);
    }
    
    auto player = WhoFirst();
    while(true) {
        
        if(player == nullptr) { break; }
        std::cout << player->GetName() << " turn" << std::endl;
        Throw3Darts(player, _pBoard);
        
        if(player->CheckWin()) break;
        player = NextPlayer();
    }
    
    for(auto p : _players) {
        p->SetBull(false);
    }
    
    DisplayEndGame(_currentPlayer);
    
	/*do
	{
        
        
        
		////////Player One Turn
        std::cout << _pOne->GetName() << " Score: " << _pOne->GetScore() << std::endl;
		Throw3Darts(_pOne, _pBoard);
        if (_pOne->GetScore() == 0) {
            break;
        }
		////////Player Two Turn
        std::cout << _pTwo->GetName() << " Score: " << _pTwo->GetScore() << std::endl;
		Throw3Darts(_pTwo, _pBoard);
	} while (_pOne->CheckWin() != true && _pTwo->CheckWin() != true);
    
    _pOne->SetBull(false);
    _pTwo->SetBull(false);
    
	DisplayWinner(_pOne, _pTwo);*/
}

void Game::Throw3Darts(GenericPlayer* player, Board* board)
{
	uint16_t _temp = player->GetScore();
    //First Throw
    if (!player->GetBusted()) //if not busted
    CheckWinningPosition(player, board); //Aim for the best possible score
    CheckBusted(player, _temp); //Check if busted
    //Second Throw
    if (!player->GetBusted())
	CheckWinningPosition(player, board);
    CheckBusted(player, _temp);
    //Third Throw
    if (!player->GetBusted())
    CheckWinningPosition(player, board);
	CheckBusted(player, _temp);
    //End turn
    player->SetBustedToFalse();
    std::cout << std::endl;
}

int16_t Game::CheckWinningPosition(GenericPlayer* player, Board* board) //Playing Nine Dart Finish Strategy
{
    if (player->GetScore() == 0) {
        return 0;
    }
    else
    {
        for (uint8_t i = 1; i >= 0; --i) //loop used to iterate through board
        {
            for (uint8_t j = 20; j >= 0; --j) //Choose the highest possible number to aim for and still be able to win
            {
                
                if ( (player->GetScore() - (board->GetAtPosition(i, j) * 2)) == 0 ) { //check if hitting double will end the game
                    player->ThrowDouble(board->GetAtPosition(i, j), board);
                    return 0;
                }
                else if ((player->GetScore()) - BULL == 0) { //check if hitting the bull will end the game
                    player->ThrowBull();
                    return 0;
                }
                else if ( ( (player->GetScore() - (j * 3)) >= 2 ) ) { //check if scoring a triple will leave at least the smallest possible winning score which is 2
                    player->ThrowTriple(j, board);
                    return 0;
                }
                else if ( (player->GetScore() - (j * 2)) >= 2 ) { //check if scoring a double will leave at least the smallest possible winning score which is 2
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
}

void Game::CheckBusted(GenericPlayer* player, uint16_t temp)
{
    if (player->GetScore() < 0 || player->GetScore() == 1 || player->GetBusted()) //Busted if score is smaller then 0 or equal to 1 or not finished on double
    {
        player->SetScore(temp);
        player->SetBustedToTrue();
    }
}

GenericPlayer* Game::WhoFirst()
{
    uint16_t percentage = rand()%100 + 1; //random number between 1-100
    do {

        for(int i = 0; i < _players.size(); ++i) {
            auto p = _players[i];
            std::cout << p->GetName() << " aims for bull!" << std::endl;
            p->ThrowBullPercentage(percentage);
            if(!p->GetBull()) {
                std::cout << p->GetName() << " missed bull!" << std::endl;
                continue;
            }
            
            _currentPlayer = i;
            std::cout << p->GetName() << " hit bull!" << std::endl;
            return p;
        }
    } while(true);
}

void Game::DisplayEndGame(std::size_t winnerIndex) {
    // we display the winner!
    std::cout << _players[winnerIndex]->GetName() << " has won this round!" << std::endl;
    _players[winnerIndex]->IncrementWinCounter();
    
    for(auto p : _players) {
        std::cout << p->GetName() << " has won " << p->GetWinCounter() << " times" << std::endl;;
    }
}

void Game::DisplayInstructions()
{
    std::cout << "Hello Fella! You are about to simulate or play exciting game of Darts 501!\n";
    std::cout << "Choose strategy:\n";
    std::cout << "1 - Cheek Strategy\n";
}




//void Game::DisplayWinner(GenericPlayer* playerOne, GenericPlayer* playerTwo)
//{
//    if (playerOne->CheckWin()) {
//        _player1WinCounter++;
//        if (_player1WinCounter == 1) {
//            std::cout << "Player One wins! He has won " << _player1WinCounter << " time!\n";
//            std::cout << "Player Two has won " << _player2WinCounter << " times!\n";
//        }
//        else {
//            std::cout << "Player One wins! He has won " << _player1WinCounter << " times!\n";
//            std::cout << "Player Two has won " << _player2WinCounter << " times!\n";
//        }
//    }
//    else if (playerTwo->CheckWin()) {
//        _player2WinCounter++;
//        if (_player2WinCounter == 1) {
//            std::cout << "Player Two wins! He has won " << _player2WinCounter << " time!\n";
//            std::cout << "Player One has won " << _player1WinCounter << " times!\n";
//        }
//        else {
//            std::cout << "Player Two wins! He has won " << _player2WinCounter << " times!\n";
//            std::cout << "Player One has won " << _player1WinCounter << " times!\n";
//        }
//    }
//    else {
//        std::cout << "Nobody has won!";
//    }
//}

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