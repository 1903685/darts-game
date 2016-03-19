#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"
class Board;

class Player : public GenericPlayer
{
public:
	Player(std::string name = "");
	~Player();

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

private:
	Board board;
	uint16_t d = 0;           //variable to hold player's aim
	//bool Fail = false;        //variable for method allowing only numeric input
	std::string _name;
	bool HitDouble = false;
	bool HitTriple = false;
	bool HitOuter = false;
	bool HitBull = false;

};


#endif /* PLAYER_H */

