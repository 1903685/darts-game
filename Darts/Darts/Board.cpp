#include <iostream>
#include <cstdint>
#include <ctime>
#include "Defines.h"
#include "Board.h"

Board::Board() {
	std::cout << "Board constructor called!\n";
	Populate();
}

Board::~Board(){
	std::cout << "Board destructor called\n";
}

const uint16_t Board::GetAtPosition(uint16_t x, uint16_t y) const {
	return _bd[x][y];
}

void Board::Populate() {
	uint16_t bd[X][Y] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	                  { 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
	
	
	for (uint8_t i = 0; i < X; ++i) {
		for (uint8_t j = 0; j < Y; ++j) {
			_bd[i][j] = bd[i][j];
		}
	}
}