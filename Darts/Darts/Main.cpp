#include <iostream>
#include <cstdint>
#include <ctime>
#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "Game.h"

using namespace std;

ostream& operator<<(ostream& os, const Board& Board);

int main()
{
	Board board1;
	Board board2;
	//board.Display();
	
	/*Matrix my_matrix(4, Column(5));
	my_matrix = { { 12 }, { 12 } };
	cout << my_matrix[1][0];*/
	
	Game game;

	//game.Play(board1, board2);

	Player one("George");
	one.NineDartFinish1(board1);
	one.ThrowTriple(20, board1);

	cout << (*board1.GetScore());

	cin.get();

	return 0;
}

ostream& operator<<(ostream& os, const Board& Board)
{
	/*Matrix board = Board.GetBoard();

	Column::iterator col_iter;
	Matrix::iterator row_iter; 

	for (row_iter = board.begin(); row_iter != board.begin(); row_iter++) {
		for (col_iter = row_iter->begin(); col_iter != row_iter->end(); col_iter++) {
			os << *col_iter << " ";
		}
		os << endl;
	}*/

	os << "\t/////////////////////";

	return os;
}

//std::vector< std::vector<int> > board(2, std::vector<int>(4));
//board.Display();
//cout << board;
//cout << board;

/*int test[100] = {0};

C std int types

int[8-16-32-64]_t		signed ints
uint[8-16-32-64]_t		unsigned ints

test[50];

*(test + 50 * sizeof(int));*/