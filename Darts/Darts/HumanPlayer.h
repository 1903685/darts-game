#pragma onceHumanPlayer
#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER

#include "GenericPlayer.h"
class Board;

class HumanPlayer
{
public:
	HumanPlayer(int16_t score = 501, std::string name = "");
	~HumanPlayer();

	virtual void SetScore(uint16_t score);
	virtual void SubtractScore(int16_t points);
	virtual int16_t GetScore();
	virtual bool IsOdd(int16_t n);
	virtual bool IsEven(int16_t n);
	virtual bool CheckWin();
	virtual void SetBusted(bool value);
	virtual bool GetBusted();
	virtual uint16_t GetWinCounter();
	virtual void IncrementWinCounter();

	virtual std::string GetName();
	virtual void SetName(std::string name);

	virtual void ThrowSingle(uint16_t d, Board* board);
	virtual void ThrowDouble(uint16_t d, Board* board);
	virtual void ThrowTriple(uint16_t d, Board* board);
	virtual bool ThrowBullPercentage(uint16_t percentage);
	virtual void ThrowBull();
	virtual void ThrowOuter();
	virtual void AimTon80(Board* board); //Aim to score 180
	virtual void AimCheckout141(Board* board); //Aim to score 141
	virtual void AimThree167s(Board* board); //Aim to score 167

private:
	int16_t _score;
	uint16_t _winCounter;
	std::string _name;
	bool _busted;
};

#endif HUMAN_PLAYER

