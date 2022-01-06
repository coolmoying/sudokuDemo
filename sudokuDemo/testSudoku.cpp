#include "widget.h"
#include "sudoku.h"
int main()
{
	Widget w(9 * WIDTH, 9 * HEIGHT);
	w.Show();
	Sudoku sudoku;
	BeginBatchDraw();
	ExMessage msg;
	while (1) 
	{
		peekmessage(&msg, EM_MOUSE);
		sudoku.DrawMap();
		sudoku.MouseMessage(msg);
		cout << sudoku.GameOver() << endl;
		if (sudoku.GameOver()) 
		{
			break;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	return  0;
}