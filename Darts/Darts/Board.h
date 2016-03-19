#pragma once
#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board(uint16_t score = 501);
	~Board();

	//friend ostream& operator<<(ostream& os, const Board& Board);
	
	void DisplayScore();
	void SetScore(int16_t& score);
	void SubtractScore(int16_t points);
	const int16_t* GetScore() const;
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

	int16_t _score;

	uint16_t _bd[X][Y];
};

#endif /* BOARD_H*/
