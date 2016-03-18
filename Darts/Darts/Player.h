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

	virtual uint16_t ThrowSingle(uint16_t d, const Board& board);
	virtual uint16_t ThrowDouble(uint16_t d, const Board& board);
	virtual uint16_t ThrowTriple(uint16_t d, const Board& board);
	virtual uint16_t ThrowBull(uint16_t percentage);

protected:
	bool HitDouble;
	bool HitTriple;
	bool HitOuter;
	bool HitBull;
};

#endif /* PLAYER_H */

