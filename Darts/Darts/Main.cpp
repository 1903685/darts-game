#include <iostream>
#include <cstdint>
#include <ctime>
#include "Defines.h"
#include "Board.h"
#include "Player.h"
#include "GenericPlayer.h"

using namespace std;

ostream& operator<<(ostream& os, const Board& Board);

int main()
{
	Board board;
	board.Display();
	
	/*Matrix my_matrix(4, Column(5));
	my_matrix = { { 12 }, { 12 } };
	cout << my_matrix[1][0];*/
	
	//std::vector< std::vector<int> > board(2, std::vector<int>(4));
	//board.Display();
	//cout << board;
	//cout << board;
	cout << BULL;

	cin.get();

	/*int test[100] = {0};

	C std int types

	int[8-16-32-64]_t		signed ints
	uint[8-16-32-64]_t		unsigned ints
	
	test[50];

	*(test + 50 * sizeof(int));*/

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