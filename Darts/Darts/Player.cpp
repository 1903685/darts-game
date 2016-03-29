#include <iostream>
#include <cstdint>
#include <ctime>
#include <string>
#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"

Player::Player(int16_t score, std::string name) : GenericPlayer(score, name) 
{ 
	std::cout << "Player constructor called!\n";
}

Player::~Player() 
{
	std::cout << "Player destructor called!\n";
}


void Player::SetScore(uint16_t score)
{
	_score = score;
}

void Player::SubtractScore(int16_t points)
{
	(_score -= points);
}

int16_t Player::GetScore()
{
	return _score;
}

bool Player::IsOdd(int16_t n)
{
	if (n % 2 != 0)
		return true;
	else
		return false;
}

bool Player::IsEven(int16_t n)
{
	if (n % 2 == 0)
		return true;
	else
		return false;
}

bool Player::CheckWin()
{
	if (_score == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Player::SetBustedToFalse()
{
    _busted = false;
}

void Player::SetBustedToTrue()
{
    _busted = true;
}

bool Player::GetBusted()
{
    return _busted;
}

std::string Player::GetName()
{
	return _name;
}

void Player::SetName(std::string name)
{
	_name = name;
}

void Player::ThrowSingle(uint16_t d, Board* board)
{
	//subtract result of throwing for single d
	//d is the score that the player is aiming for

	uint16_t r = (rand() % 100 + 1);
	std::cout << "Aim Single: " << d << std::endl;

	if (d == OUTER) //throw outer bull with 80% accuracy
	{
		ThrowOuter();
	}

	else if (d == BULL) //throw bull with 80% accuracy
	{
		ThrowBull();
	}
	else if (r <= 70) // 70% chance for 1 to 20 single 
	{
		SubtractScore(d); //subtract score
		std::cout << "Scored Single: " << d << " Score: " << _score << std::endl;
	} 
	else if (r > 70 && r <= 80) //10% chance for scoring left
	{
		SubtractScore(board->GetAtPosition(0, d)); //subtract score from the left
		std::cout << "Scored Single Left: " << board->GetAtPosition(0, d) << " Score: " << _score << std::endl;
	} 
	else if (r > 80 && r <= 90 ) //10% chance for scoring right
	{
		SubtractScore(board->GetAtPosition(1, d)); //subtract score from the right
		std::cout << "Scored Single Right: " << board->GetAtPosition(1, d) << " Score: " << _score << std::endl;
	} 
	else if (r > 90 && r <= 95) //5% chance for scoring double
	{
		SubtractScore(2 * d); //subtract double score
		std::cout << "Scored Double: " << 2 * d << " Score: " << _score << std::endl;
	}
	else //5% chance for scoring triple
	{
		SubtractScore(3 * d); //subtract triple score
        if (GetScore() == 0) {
            SetBustedToTrue();
        }
		std::cout << "Scored Triple: " << 3 * d << " Score: " << _score << std::endl;
	}
}

void Player::ThrowDouble(uint16_t d, Board* board)
{
	//subtract result of throwing for single d
	//d is the score that the player is aiming for
	std::cout << "Aim Double " << d << std::endl;;
	uint16_t r = (rand() % 100 + 1);

	if (d == OUTER) // outer bull 80% accuracy
	{
		ThrowOuter();
	}

	else if (d == BULL) // outer  bull 80% accuracy
	{
		ThrowBull();
	}
	else if (r <= 70) // 70% chance for double
	{
		SubtractScore(2 * d); //subtract double score
		std::cout << "Scored Double: " << 2 * d << " Score: " << _score << std::endl;
	}
	else if (r > 70 && r <= 80) //10% chance for scoring double left
	{
		SubtractScore(2 * (board->GetAtPosition(0, d) )); //subtract double score from the left
		std::cout << "Scored Double Left: " << 2 * (board->GetAtPosition(0, d)) << " Score: " << _score << std::endl;
	}
	else if (r > 80 && r <= 90) //10% chance for scoring double right
	{
		SubtractScore(2 * (board->GetAtPosition(1, d)) ); //subtract double score from the right
		std::cout << "Scored Double Right: " << 2 * (board->GetAtPosition(1, d)) << " Score: " << _score << std::endl;
	}
	else //10% chance for scoring single
	{
		SubtractScore(d); //subtract single score
		std::cout << "Scored Single: " << d << " Score: " << _score << std::endl;
	}
}

void Player::ThrowTriple(uint16_t d, Board* board)
{
	//subtract result of throwing for single d
	//d is the score that the player is aiming for

	uint16_t r = (rand() % 100 + 1);

    std::cout << "Aim Triple " << d << std::endl;
    
	if (r <= 70) // 70% chance for triple
	{
        SubtractScore(3 * d); //subtract triple score
        if (GetScore() == 0) {
            SetBustedToTrue();
        }
		std::cout << "Scored Triple: " << 3 * d << " Score: " << _score << std::endl;
		//*board->GetScore()) - 3 * d;
	}
	else if (r > 70 && r <= 80) //10% chance for scoring triple left
	{
		SubtractScore(3 * (board->GetAtPosition(0, d)) ); //subtract triple score from the left
        if (GetScore() == 0) {
            SetBustedToTrue();
        }
		std::cout << "Scored Triple Left: " << 3 * (board->GetAtPosition(0, d)) << " Score: " << _score << std::endl;
	}
	else if (r > 80 && r <= 90) //10% chance for scoring triple right
	{
		SubtractScore(3 * (board->GetAtPosition(1, d)) ); //subtract triple score from the right
        if (GetScore() == 0) {
            SetBustedToTrue();
        }
		std::cout << "Scored Triple Right: " << 3 * (board->GetAtPosition(1, d)) << " Score: " << _score << std::endl;
	}
	else if (r > 90 && r <= 95) //5% chance for scoring single left
	{
		SubtractScore(board->GetAtPosition(0, d));
		std::cout << "Scored Single Left: " << (board->GetAtPosition(0, d)) << " Score: " << _score << std::endl;
	}
	else //5% chance for scoring single right
	{
		SubtractScore(board->GetAtPosition(1, d));
		std::cout << "Scored Single Right: " << (board->GetAtPosition(1, d)) << " Score: " << _score << std::endl;
	}
}

void Player::ThrowBullPercentage(uint16_t percentage, Board* board)
{
	//  Throw for the bull with given accuracy
	int r = (rand() % 100 + 1);
	std::cout << "Aim Bull ";
	if (r <= percentage) //happens with custom percentage chance
	{
		SubtractScore(BULL);
		std::cout << "Scored Bull: " << BULL << " Score: " << _score << std::endl;
	}
	else if (r > percentage && r < percentage + 20) //happens with 20% chance
	{
		SubtractScore(OUTER);
		std::cout << "Scored Outer: " << OUTER << " Score: " << _score << std::endl;
	}
	else //happens with remaining percentage
	{
		SubtractScore(rand() % 20 + 1);
		std::cout << "Scored Random: " << rand() % 20 + 1 << " Score: " << _score << std::endl;
	}
}

void Player::ThrowBull()
{
	int r = rand() % 100 + 1;

	if (r <= 80) //80% chance
	{
		SubtractScore(BULL); //subtract red inner bull from score
		std::cout << "Scored Bull: " << BULL << " Score: " << _score << std::endl;
	}
	else if (r > 80 && r <= 90) //10% chance
	{
		SubtractScore(OUTER); //subtract outer bull from score
		std::cout << "Scored Outer: " << OUTER << " Score: " << _score << std::endl;
	}
	else
	{
		SubtractScore(rand() % 20 + 1); //subtract a random score between 1 and 20
		std::cout << "Scored Random: " << (rand() % 20 + 1) << " Score: " << _score << std::endl;
	}
}
void Player::ThrowOuter()
{
	int r = rand() % 100 + 1;

	if (r <= 80) //80% chance
	{
		SubtractScore(OUTER); //subtract outer bull from score
		std::cout << "Scored Outer: " << OUTER << " Score: " << _score << std::endl;
	}
	else if (r > 80 && r <= 90) //10% chance
	{
		SubtractScore(BULL); //subtract red inner bull from score
		std::cout << "Scored Bull: " << BULL << " Score: " << _score << std::endl;
	}
	else
	{
		SubtractScore(rand() % 20 + 1); //subtract a random score between 1 and 20
		std::cout << "Scored Random: " << (rand() % 20 + 1) << " Score: " << _score << std::endl;
	}
}

void Player::AimTon80(Board* board) //Aim to score 180
{
	ThrowTriple(20, board);
	ThrowTriple(20, board);
	ThrowTriple(20, board);
}

void Player::AimCheckout141(Board* board) //Aim to score 141
{
	ThrowTriple(20, board);
	ThrowTriple(19, board);
	ThrowDouble(12, board);
}

void Player::AimThree167s(Board* board) //Aim to score 167
{
	ThrowTriple(20, board);
	ThrowTriple(19, board);
	ThrowBullPercentage(100, board);
}

void Player::NineDartFinish1(Board* board)
{
    AimTon80(board);
	AimTon80(board);
	AimCheckout141(board);
}

void Player::NineDartFinish2(Board* board)
{
	AimTon80(board);
	AimTon80(board);
	AimThree167s(board);
}