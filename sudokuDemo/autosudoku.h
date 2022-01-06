#pragma once
#include "common.h"
class Autosudoku 
{
public:
	Autosudoku(array<array<int, 9>, 9>& data);
	int* GetNextSpace(int board[][9], int rowStart, int colStart);
	bool ValidateBoard(int board[][9], int i, int j, int k);
	void GetResult(int board[][9], int i, int j);
protected:
	int board[9][9];
};