#pragma once
#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board();
	~Board();

	//friend ostream& operator<<(ostream& os, const Board& Board);

	const uint16_t GetAtPosition(uint16_t x, uint16_t y) const;
	/*const Matrix& GetBoard() const;
	const Matrix::iterator& GetFirst();*/
	void Display();
	void Populate();

private:
	/*Row(columns);
	Matrix _board(int rows, Row());*/
	//std::vector<int> _columns;
	//std::vector< std::vector<int> > _board;
	/*Column::iterator col_iter;
	Matrix::iterator row_iter;
	Matrix _board;*/

	uint16_t _bd[X][Y];
};

#endif /* BOARD_H*/
