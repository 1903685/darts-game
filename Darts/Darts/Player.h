#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"
class Board;

class Player : public GenericPlayer
{
public:
	Player(bool hitDouble = false, bool hitTriple = false, bool hitOuter = false, bool hitBull = false);
	~Player();

	virtual void SimpleStrategy( Board& board);

protected:
	bool HitDouble;
	bool HitTriple;
	bool HitOuter;
	bool HitBull;

	virtual void ThrowSingle(uint16_t d, Board& board);
	virtual void ThrowDouble(uint16_t d, Board& board);
	virtual void ThrowTriple(uint16_t d, Board& board);
	virtual void ThrowBull(uint16_t percentage, Board& board);
};


#endif /* PLAYER_H */

