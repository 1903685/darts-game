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

	virtual void SetScore(uint16_t score);
	virtual void SubtractScore(int16_t points);
	virtual int16_t GetScore();
	virtual bool IsOdd(int16_t n);
	virtual bool IsEven(int16_t n);
	virtual bool CheckWin();
    virtual void SetBustedToFalse();
    virtual void SetBustedToTrue();
    virtual bool GetBusted();
    virtual void SetBull(bool value);
    virtual bool GetBull();

	virtual std::string GetName();
	virtual void SetName(std::string name);

	virtual void ThrowSingle(uint16_t d, Board* board);
	virtual void ThrowDouble(uint16_t d, Board* board);
	virtual void ThrowTriple(uint16_t d, Board* board);
	virtual void ThrowBullPercentage(uint16_t percentage);
	virtual void ThrowBull();
	virtual void ThrowOuter();
	virtual void AimTon80(Board* board);
	virtual void AimCheckout141(Board* board);
	virtual void AimThree167s(Board* board);

	virtual void NineDartFinish1(Board* board);
	virtual void NineDartFinish2(Board* board);
    
    
    virtual uint16_t GetWinCounter();
    virtual void IncrementWinCounter();
    
private:
    int16_t _score;
    uint16_t _winCounter;
    std::string _name;
    bool _busted;
    bool _hitBull;
};


#endif /* PLAYER_H */

