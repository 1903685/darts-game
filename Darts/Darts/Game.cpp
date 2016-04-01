#include <iostream>
#include "Game.h"

Game::Game() : _players(0), _currentPlayer(0) {}

Game::~Game()
{
	std::cout << "Game destructor called!\n";
	delete _pBoard;
    _pBoard = nullptr;
}

//void Game::Play(const std::vector<GenericPlayer*>& players)
void Game::Play()
{
    srand(static_cast<unsigned int>(time(0)));

    _currentPlayer = 0;
    
    for(auto* p : _players) { //make sure there are no remaining pointers in vector of players
        delete p;
    }
    _players.clear(); //removes all elements from the vector
    
    uint16_t numPlayers = SetNumPlayers();
//    PushNames(SetNumPlayers(), _names);
    PushNames(numPlayers);
    
    for (auto& name : _names) {
        _players.push_back(new Player(501, name));
    }
    
	std::cout << "How many times you want to play? ";
	std::cin >> _simulateCounter;
	std::cout << std::endl;

	for (uint32_t i = 0; i < _simulateCounter; ++i)
	{
			PlayNineDartFinish();
	}
	std::cin.get();
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
    for(auto p : _players) {
        p->SetScore(_newScore);
    }
    
    auto player = WhoFirst();
    while(true) {
        
        if(player == nullptr) //if p is empty break loop
            break;
        
        std::cout << player->GetName() << " Turn. " << "Score: " << player->GetScore() << std::endl;
        Throw3Darts(player, _pBoard); // Each player throws 3 darts
        
        if(player->CheckWin()) // if current player wins break loop
            break;
        
        player = NextPlayer(); // if current player does not win set p to next player
    }
    
    DisplayEndGame(_currentPlayer);
}

GenericPlayer* Game::GetCurrentPlayer() {
    if(_players.size() == 0) return nullptr;
    return _players[_currentPlayer];
}

GenericPlayer* Game::NextPlayer() { //get next player
    if(_players.size() == 0) return nullptr;
    _currentPlayer++;
    _currentPlayer %= _players.size(); //cp = 0, 1%4 = 1, 2%4 = 2, 3%4= 3, 4%4 = 0
    return _players[_currentPlayer];
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
    player->SetBusted(false);
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
        player->SetBusted(true);
    }
}

GenericPlayer* Game::WhoFirst()
{ //determines who throws first
    do { // aim for bull until someone scores

        for(uint i = 0; i < _players.size(); ++i) //every player aims for bull
        {
            auto p = _players[i]; //set p to player who aims for bull
            std::cout << p->GetName() << " aims for bull!" << std::endl;

            if(!p->ThrowBullPercentage(50)) //aim bull with 50% accuracy
            { //if not hit the bull continue with next player
                std::cout << p->GetName() << " missed bull!" << std::endl;
                continue;
            }
            //happens if the players scores the bull
            _currentPlayer = i; //set _currentPlayer value to value position of player
//            who scored bull (if player 1 scored bull set _currentPosition to 0)
            std::cout << p->GetName() << " hit bull!" << std::endl << std::endl;
            return p; //returns pointer to player who scored bull
        }
    } while(true);
}

void Game::DisplayEndGame(std::size_t winnerIndex)
{   // display winner
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