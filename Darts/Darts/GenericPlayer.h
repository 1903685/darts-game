#pragma once
#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

class Board;

class GenericPlayer
{
public:
	virtual ~GenericPlayer() {}

	virtual uint16_t ThrowSingle(uint16_t d, const Board& board) = 0;
	virtual uint16_t ThrowDouble(uint16_t d, const Board& board) = 0;
	virtual uint16_t ThrowTriple(uint16_t d, const Board& board) = 0;
	virtual uint16_t ThrowBull(uint16_t percentage) = 0;
};

#endif