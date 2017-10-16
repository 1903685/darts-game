#pragma once
#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board();
	~Board();

	const uint16_t GetAtPosition(uint16_t x, uint16_t y) const;

	void Display();
	void Populate();

private:
	uint16_t _bd[X][Y];
};

#endif /* BOARD_H*/
