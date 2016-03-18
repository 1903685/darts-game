#pragma once
#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

class Board;

class GenericPlayer
{
public:
	virtual ~GenericPlayer() {}

	virtual void ThrowSingle(uint16_t d, Board& board) = 0;
	virtual void ThrowDouble(uint16_t d, Board& board) = 0;
	virtual void ThrowTriple(uint16_t d, Board& board) = 0;
	virtual void ThrowBull(uint16_t percentage, Board& board) = 0;
	virtual void AimTon80(Board& board) = 0;
	virtual void AimCheckout141(Board& board) = 0;
	virtual void AimThree167s(Board& board) = 0;

	virtual void NineDartFinish1(Board& board) = 0;
	virtual void NineDartFinish2(Board& board) = 0;
	virtual void AdvancedStrategy( Board& board) = 0;
};

#endif