#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"
class Board;

class Player : public GenericPlayer
{
public:
	Player(int16_t score = 501, std::string name = "");
	~Player();

	virtual void SetScore(int16_t score);
	virtual void SubtractScore(int16_t points);
	virtual int16_t GetScore();

	virtual std::string GetName();
	virtual void SetName(std::string name);

	virtual void ThrowSingle(uint16_t d, Board& board);
	virtual void ThrowDouble(uint16_t d, Board& board);
	virtual void ThrowTriple(uint16_t d, Board& board);
	virtual void ThrowBull(uint16_t percentage, Board& board);
	virtual void AimTon80(Board& board);
	virtual void AimCheckout141(Board& board);
	virtual void AimThree167s(Board& board);

	virtual void NineDartFinish1(Board& board);
	virtual void NineDartFinish2(Board& board);

	virtual void AdvancedStrategy(Board& board);

private:
	//uint16_t _score;
	//uint16_t d = 0;           //variable to hold player's aim
	//bool Fail = false;        //variable for method allowing only numeric input
	//std::string _name;
	/*int16_t _score;
	std::string _name = "";*/
	/*bool HitDouble = false;
	bool HitTriple = false;
	bool HitOuter = false;
	bool HitBull = false;*/

};


#endif /* PLAYER_H */

