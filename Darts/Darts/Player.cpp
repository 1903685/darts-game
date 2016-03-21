#include <iostream>
#include <cstdint>
#include <ctime>
#include <string>
#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"

Player::Player(int16_t score, std::string name) : GenericPlayer(score, name) {}

Player::~Player() {}

int16_t Player::GetScore()
{
	return _score;
}

void Player::SetScore(int16_t score)
{
	_score = score;
}

void Player::SubtractScore(int16_t points)
{
	(_score -= points);
}

std::string Player::GetName()
{
	return _name;
}

void Player::SetName(std::string name)
{
	_name = name;
}

void Player::ThrowSingle(uint16_t d, Board& board)
{
	//subtract result of throwing for single d
	//d is the score that the player is aiming for

	uint16_t r = (rand() % 100 + 1);

	if (d == OUTER) // outer bull 80% accuracy
	{
		if (r <= 80) //80% chance
		{
			HitOuter = true;
			SubtractScore(OUTER); //subtract outer bull from score
		}
		else if (r > 80 && r <= 90) //10% chance
		{
			HitBull = true;
			SubtractScore(BULL); //subtract red inner bull from score
		}
		else
		{
			SubtractScore(rand() % 20 + 1); //subtract a random score between 1 and 20
		}
	}

	else if (d == BULL) // outer  bull 80% accuracy
	{
		if (r <= 80) //80% chance
		{
			HitBull = true;
			SubtractScore(BULL); //subtract red inner bull from score
		} 
		else if (r > 80 && r <= 90) //10% chance
		{
			HitOuter = true;
			SubtractScore(OUTER); //subtract outer bull from score
		} 
		else
		{
			SubtractScore(rand() % 20 + 1); //subtract a random score between 1 and 20
		} 
	}

	else if (r <= 70) // 70% chance for 1 to 20 single 
	{
		SubtractScore(d); //subtract score
	} 
	else if (r > 70 && r <= 80) //10% chance for scoring left
	{
		SubtractScore(board.GetAtPosition(0, d)); //subtract score from the left
	} 
	else if (r > 80 && r <= 90 ) //10% chance for scoring right
	{
		SubtractScore(board.GetAtPosition(1, d)); //subtract score from the right
	} 
	else if (r > 90 && r <= 95) //5% chance for scoring double
	{
		HitDouble = true;
		SubtractScore(2 * d); //subtract double score
	}
	else //5% chance for scoring triple
	{
		HitTriple = true;
		SubtractScore(3 * d); //subtract triple score
	}
}

void Player::ThrowDouble(uint16_t d, Board& board)
{
	//subtract result of throwing for single d
	//d is the score that the player is aiming for

	uint16_t r = (rand() % 100 + 1);

	if (r <= 70) // 70% chance for double
	{
		HitDouble = true;
		SubtractScore(2 * d); //subtract double score
	}
	else if (r > 70 && r <= 80) //10% chance for scoring double left
	{
		SubtractScore(2 * (board.GetAtPosition(0, d) )); //subtract double score from the left
	}
	else if (r > 80 && r <= 90) //10% chance for scoring double right
	{
		SubtractScore(2 * (board.GetAtPosition(1, d)) ); //subtract double score from the right
	}
	else //10% chance for scoring single
	{
		SubtractScore(d); //subtract single score
	}
}

void Player::ThrowTriple(uint16_t d, Board& board)
{
	//subtract result of throwing for single d
	//d is the score that the player is aiming for

	uint16_t r = (rand() % 100 + 1);

	if (r <= 70) // 70% chance for triple
	{
		SubtractScore(3 * d); //subtract triple score
		//*board.GetScore()) - 3 * d;
	}
	else if (r > 70 && r <= 80) //10% chance for scoring triple left
	{
		SubtractScore(3 * (board.GetAtPosition(0, d)) ); //subtract triple score from the left
	}
	else if (r > 80 && r <= 90) //10% chance for scoring triple right
	{
		SubtractScore(3 * (board.GetAtPosition(1, d)) ); //subtract triple score from the right
	}
	else if (r > 90 && r <= 95) //5% chance for scoring single left
	{
		SubtractScore(board.GetAtPosition(0, d));
	}
	else //5% chance for scoring single right
	{
		SubtractScore(board.GetAtPosition(1, d));
	}
}

void Player::ThrowBull(uint16_t percentage, Board& board)
{
	//  Throw for the bull with given accuracy
	int r = (rand() % 100 + 1);

	if (r <= percentage) //happens with custom percentage chance
	{
		SubtractScore(BULL);
	}
	else if (r > percentage && r < percentage + 20) //happens with 20% chance
	{
		SubtractScore(OUTER);
	}
	else //happens with remaining percentage
	{
		SubtractScore(rand() % 20 + 1);
	}
}

void Player::AimTon80(Board& board) //Aim to score 180
{
	ThrowTriple(20, board);
	std::cout << "Throw Triple: " << _score << std::endl;
	ThrowTriple(20, board);
	std::cout << "Throw Triple: " << _score << std::endl;
	ThrowTriple(20, board);
	std::cout << "Throw Triple: " << _score << std::endl;
}

void Player::AimCheckout141(Board& board) //Aim to score 141
{
	ThrowTriple(20, board);
	std::cout << "Throw Triple: " << _score << std::endl;
	ThrowTriple(19, board);
	std::cout << "Throw Triple: " << _score << std::endl;
	ThrowDouble(12, board);
	std::cout << "Throw Double: " << _score << std::endl;
}

void Player::AimThree167s(Board& board) //Aim to score 167
{
	ThrowTriple(20, board);
	ThrowTriple(19, board);
	ThrowBull(100, board);
}

void Player::NineDartFinish1(Board& board)
{
	/*do {
		cout << "Aim: ";
		cin >> d;
		cout << endl;
		Fail = cin.fail();

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (Fail);*/
	AimTon80(board);
	AimTon80(board);
	AimCheckout141(board);
}

void Player::NineDartFinish2(Board& board)
{
	AimTon80(board);
	AimTon80(board);
	AimThree167s(board);
}

void Player::AdvancedStrategy(Board& board)
{
	do
	{







	} while (_score != 0);
}