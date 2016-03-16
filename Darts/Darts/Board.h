#pragma once
using namespace std;

class Board
{
public:
	Board(int score = 501, int rows = 2, int columns = 21);
	~Board();

	friend std::ostream& operator<<(std::ostream& os, const Board& Board);

	void SetScore(int& score);
	int* GetScore();
	const Matrix& GetBoard() const;
	const Matrix::iterator& GetFirst();
	void Display();
	void Populate();

protected:
	/*Row(columns);
	Matrix _board(int rows, Row());*/
	//std::vector<int> _columns;
	//std::vector< std::vector<int> > _board;
	Column::iterator col_iter;
	Matrix::iterator row_iter;
	Matrix _board;

	int _score;
};

