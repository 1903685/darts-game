#include <iostream>
#include <vector>
#include <iterator>
#include "Defines.h"
#include "Board.h"

using namespace std;

Board::Board(int score, int rows, int columns) :
_board(rows, Column(columns))
{
	Populate();
}


//Board::Board(int score, int rows, int columns)
//{
//	Populate();
//}

//Board::Board()
//{
//	Populate();
//}

Board::~Board()
{
	cout << "Board destructor called";
}

int* Board::GetScore()
{
	return &_score;
}

void Board::SetScore(int& score)
{
	_score = score;
}

const Matrix& Board::GetBoard() const
{
	return _board;
}

const Matrix::iterator& Board::GetFirst()
{
	return _board.begin();
}

void Board::Display()
{
	/*for (auto i : _board)
	{
		cout << i << endl;
	}*/

	/*vector< vector<int> >::iterator row_iter;
	vector<int>::iterator col_iter;*/

	for (row_iter = _board.begin(); row_iter != _board.end(); row_iter++)
	{
		for (col_iter = row_iter->begin(); col_iter != row_iter->end(); col_iter++) 
		{
			cout << *col_iter << " ";
		}
		cout << endl;
	}

	/*for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			cout << _board[i][j] << " ";
		}
		cout << endl;
	}*/
}

void Board::Populate()
{
	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
	                  { 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };

	for (int i = 0; i < 2; ++i) 
	{
		for (int j = 0; j < 21; ++j)
		{
			_board[i][j] = bd[i][j];
		}
	}
}

//int throw_single(int d)
//{//  return result of throwing for single d with accuracy 88% (or 80% for the outer)
//	//d is the score that the player is aiming for
//
//	// Board neighbours ignoring slot zero – this might be better stored in a board class
//	int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
//	{ 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
//	int r = (rand() % 100 + 1);
//
//	if (d == 25){	// outer  bull 80% accuracy
//		if (r < 80)
//		{
//			return 25;
//		} //throw was successful
//		else if (r < 90)
//		{
//			return 50;
//		} //red inner bull hit instead
//		else
//		{
//			return 1 + rand() % 20;
//		} //return a random score between 1 and 20
//	}
//	else if (r < 88)		// 1 to 20 single
//	{
//		return d;
//	} //return score
//	else if (r < 92)
//	{
//		return bd[0][d];
//	} //return score to the left
//	else if (r < 96)
//	{
//		return bd[1][d];
//	} //return score to the right
//	else if (r < 98)
//	{
//		return 3 * d;
//	}//return random score?? Improve this?
//	else
//	{
//		return 2 * d;
//	} //return random score?? Improve this?
//}