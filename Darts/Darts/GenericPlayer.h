#pragma once
#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <string>
class Board;
class Player;

class GenericPlayer
{
public:
	GenericPlayer(int16_t score, std::string name) : _score(score), _name(name) {}
	virtual ~GenericPlayer() {}
	//score functions
	virtual void SetScore(uint16_t score) = 0;
	virtual void SubtractScore(int16_t points) = 0;
	virtual int16_t GetScore() = 0;
	virtual bool IsOdd(int16_t n) = 0;
	virtual bool IsEven(int16_t n) = 0;
	virtual bool CheckWin() = 0;
    virtual void SetBustedToFalse() = 0;
    virtual void SetBustedToTrue() = 0;
    virtual bool GetBusted() = 0;
    virtual void SetBull(bool value) = 0;
    virtual bool GetBull() = 0;
    
    virtual Player WhoFirst(Player* playerOne, Player* playerTwo, Board *board) = 0;

	virtual std::string GetName() = 0;
	virtual void SetName(std::string name) = 0;

	virtual void ThrowSingle(uint16_t d, Board* board) = 0;
	virtual void ThrowDouble(uint16_t d, Board* board) = 0;
	virtual void ThrowTriple(uint16_t d, Board* board) = 0;
	virtual void ThrowBullPercentage(uint16_t percentage, Board* board) = 0;
	virtual void ThrowBull() = 0;
	virtual void ThrowOuter() = 0;
	virtual void AimTon80(Board* board) = 0;
	virtual void AimCheckout141(Board* board) = 0;
	virtual void AimThree167s(Board* board) = 0;

	virtual void NineDartFinish1(Board* board) = 0;
	virtual void NineDartFinish2(Board* board) = 0;

protected:
	int16_t _score = 501;
	std::string _name = "";
    bool _busted = false;
    bool _hitBull = false;
};

#endif