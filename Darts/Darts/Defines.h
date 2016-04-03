#ifndef DEFINES_H
#define DEFINES_H

#include <cstdint>
#include <Windows.h>

const uint16_t TON = 100;
const uint16_t BULL = 50;
const uint16_t OUTER = 25;
const uint16_t X = 2;
const uint16_t Y = 21;
enum Choice { Exit, CompVsComp, CompVsHuman, HumanVsHuman };
const WORD colors[] =
{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};

//typedef std::vector<int> Column;	// One Column of the matrix
//typedef std::vector<Column> Matrix; // Matrix: a vector of Columns
//typedef std::vector<int>::iterator col_iter;
//typedef std::vector< std::vector<int> >::iterator row_iter;

<<<<<<< HEAD
#endif
=======
#endif


/*Matrix my_matrix(4, Column(5));
	my_matrix = { { 12 }, { 12 } };
	cout << my_matrix[1][0];*/
>>>>>>> master
