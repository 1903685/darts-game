#include <iostream>
#include <cstdint>
#include <ctime>
#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"

using namespace std;

Player::Player(bool hitDouble, bool hitTriple, bool hitBool) :
	HitDouble(hitDouble), 
	HitTriple(hitTriple), 
	HitBool(hitBool)
{}

Player::~Player()
{
}

uint16_t Player::ThrowSingle(uint16_t d, const Board& board)
{
	//return result of throwing for single d
	//d is the score that the player is aiming for

	srand(static_cast<unsigned int>(time(0)));

	uint16_t r = (rand() % 100 + 1);

	if (d == OUTER) // outer bull 80% accuracy
	{
		if (r < 80) //80% chance
		{
			return OUTER; //throw was successful
		}
		else if (r >= 80 && r < 90) //10% chance
		{
			return BULL; //red inner bull hit instead
		}
		else
		{
			return rand() % 20 + 1; //return a random score between 1 and 20
		}
	}

	else if (d == BULL) // outer  bull 80% accuracy
	{
		if (r < 80) //80% chance
		{
			return BULL; //throw was successful
		} 
		else if (r >= 80 && r < 90) //10% chance
		{
			return OUTER; //outer bull hit instead
		} 
		else
		{
			return rand() % 20 + 1; //return a random score between 1 and 20
		} 
	}

	else if (r < 70) // 70% chance for 1 to 20 single 
	{
		return d; //return score
	} 
	else if (r >= 70 && r < 80) //10% chance for scoring left
	{
		return board.GetAtPosition(0,d); //return score to the left
	} 
	else if (r >= 80 && r < 90 ) //10% chance for scoring right
	{
		return board.GetAtPosition(1,d); //return score to the right
	} 
	else if (r >= 90 && r < 95) //5% chance for scoring double
	{
		return 2 * d; //return double score
	}
	else //5% chance for scoring triple
	{
		return 3 * d; //return triple score
	}
}

//int16_t Player::ThrowDouble(uint16_t d, const Board& board)
//{
//	return d;
//}
