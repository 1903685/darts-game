#include <iostream>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Defines.h"
#include "Game.h"

Game::Game() : _players(0), _currentPlayer(0), _choice(1), _newScore(501), _temp(0), _simulateCounter(0) {}

Game::~Game() {} //There is no deleting of pointers in vector of pointers '_players' or Board object
				 //because they are all deleted when Game construstor is called anyway

void Game::Play() {
	srand(static_cast<unsigned int>(time(0)));
	
	while (_choice != 0) {
		for (auto* p : _players) { //make sure there are no remaining pointers in vector of players
			delete p;
		}
		_players.clear(); //removes all elements from the vector

		DisplayInstructions();
		std::cout << "Choice: ";
		std::cin >> _choice;

		switch (_choice) {
			case (Exit) : {
				_choice = 0;
			} break;

			case (Simulation) : {
				uint16_t numPlayers = SetNumPlayers();
				PushNames(numPlayers);

				for (auto& name : _names) {
					_players.push_back(new Player(501, name)); //creating new player
				}

				std::cout << "How many times you want to play? ";
				std::cin >> _simulateCounter;
				std::cout << std::endl;

				for (int32_t i = 0; i < _simulateCounter; ++i) {
					std::cout << "Simulation: " << i + 1 << std::endl << std::endl;
					PlayNineDartFinish(_players);
				}
			} break;

			default: break;
		}
	}
}

void Game::PushNames(uint16_t numPlayers) {
    std::string name;
    for (uint16_t i = 0; i < numPlayers; ++i) {
        std::cout << "Player " << i + 1 << " name: ";
        std::cin >> name;
        _names.push_back(name);
    }
}

uint16_t Game::SetNumPlayers() {
    uint16_t numPlayers = 0;
    std::cout << "How many players? ";
    std::cin >> numPlayers;
    
    return numPlayers;
}

void Game::PlayNineDartFinish(const std::vector<GenericPlayer*>& players) {	
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember how things were at the beginning
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

    for(auto p : players) {
        p->SetScore(_newScore);
    }
    
    auto player = WhoFirst();
    while(true) {
        if(player == nullptr) break; //if p is empty break loop
		
		WORD color = _currentPlayer + 2;
		if ( color >= 16 || color == 0) color = 3; //there's only 16 colors and 0 is black

		SetConsoleTextAttribute(hstdout, color);

        std::cout << player->GetName() << " Turn. " << "Score: " << player->GetScore() << std::endl;
        Throw3Darts(player, _pBoard); // Each player throws 3 darts
        
        if(player->CheckWin()) break; // if current player wins break loop
        
        player = NextPlayer(); // if current player does not win set p to next player
    }
	//Flush the buffer in order to prepare for the new simulation
	FlushConsoleInputBuffer(hstdin);
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);

    DisplayEndGame(_currentPlayer);
	
    std::cout << std::endl;
}

GenericPlayer* Game::NextPlayer() { //get next player
    if(_players.size() == 0) return nullptr;
    _currentPlayer++;
    _currentPlayer %= _players.size(); //cp = 0, 1%4 = 1, 2%4 = 2, 3%4= 3, 4%4 = 0
    return _players[_currentPlayer];
}

void Game::Throw3Darts(GenericPlayer* player, Board* board) {
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
    player->SetBusted(false);
    std::cout << std::endl;
}

int16_t Game::CheckWinningPosition(GenericPlayer* player, Board* board) { //Playing Nine Dart Finish Strategy
    if (player->GetScore() == 0) {
        return 0;
    }
    else {
        for (uint8_t i = 1; i >= 0; --i) { //loop used to iterate through board

            for (uint8_t j = 20; j >= 0; --j) { //Choose the highest possible number to aim for and still be able to win

                if ((player->GetScore()) - BULL == 0) { //check if hitting the bull will end the game
                    player->ThrowBull();
                    return 0;
                }
                else if ( (player->GetScore() - (board->GetAtPosition(i, j) * 2)) == 0 ) { //check if hitting double will end the game
					player->ThrowDouble(board->GetAtPosition(i, j), board);
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

void Game::CheckBusted(GenericPlayer* player, uint16_t temp) {
    if (player->GetScore() < 0 || player->GetScore() == 1 || player->GetBusted()) //Busted if score is smaller then 0 or equal to 1 or not finished on double
    {
        player->SetScore(temp);
        player->SetBusted(true);
    }
}

GenericPlayer* Game::WhoFirst() { //determines who throws first
    do { // aim for bull until someone scores

        for(long i = _currentPlayer; i < _players.size(); ++i) //last wining player aims bull first
        {
            auto player = _players[i]; //set p to player who aims for bull
            std::cout << player->GetName() << " aims for bull!" << std::endl;

            if(!player->ThrowBullPercentage(50)) //aim bull with 50% accuracy
            { //if not hit the bull continue with next player
                std::cout << player->GetName() << " missed bull!" << std::endl;
                continue;
            }
            //happens if the players scores the bull
            _currentPlayer = i; //set _currentPlayer value to value position of player
//            who scored bull (if player 1 scored bull set _currentPosition to 0)
            std::cout << player->GetName() << " hit bull!" << std::endl << std::endl;
            return player; //returns pointer to player who scored bull
        }
    } while(true);
}

void Game::DisplayEndGame(std::size_t winnerIndex) {   // display winner
    std::cout << _players[winnerIndex]->GetName() << " has won this round!" << std::endl;
    _players[winnerIndex]->IncrementWinCounter();
    
    for(auto p : _players) {
        std::cout << p->GetName() << " has won " << p->GetWinCounter() << " times" << std::endl;
    }
}

void Game::DisplayInstructions() {
	std::cout << "\n\nWeclome to the Darts 501 Game Simulator!";
	std::cout << "\nYou can choose how many players will compete";
	std::cout << "\nAs well as how many games you want to simulate.";
	std::cout << "\nPlayers will throw 3 darts for a turn.";
	std::cout << "\nThe score and throws will be displayed like this:";
	std::cout << "\n'Turn number' 'Score'";
	std::cout << "\n'Player's aim'";
	std::cout << "\n'Player's hit score'('Exact hit score') 'New score = Old Score - Hit Score'";
	std::cout << "Press:\n";
	std::cout << "1 - Simulate\n";
	std::cout << "0 - Exit\n";
}