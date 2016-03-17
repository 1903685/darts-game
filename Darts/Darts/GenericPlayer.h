#pragma once
#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "Board.h"
#include "Player.h"

class GenericPlayer
{
public:
	GenericPlayer() {}
	virtual ~GenericPlayer() = 0;

	virtual uint16_t ThrowSingle(uint16_t d, const Board& board) = 0;
	virtual uint16_t ThrowDouble(uint16_t d, const Board& board) = 0;
	virtual uint16_t ThrowTriple(uint16_t d, const Board& board) = 0;
	virtual uint16_t ThrowBull(uint16_t percentage) = 0;
};

#endif