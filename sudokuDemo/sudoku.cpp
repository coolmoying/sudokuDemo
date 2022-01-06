#include "button.h"
#include "widget.h"
#include "sudoku.h"
#include "timer.hpp"
Sudoku::Sudoku()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			int x = WIDTH * j;
			int y = HEIGHT * i;
			if (map[i][j] != 0) 
			{
				rect.push_back(
					make_pair<bool, Button*>(false, new Button(to_string(map[i][j]), x, y, 60, 60,LIGHTGREEN)));
			}
			else 
			{
				rect.push_back(
					make_pair<bool, Button*>(true, new Button(to_string(map[i][j]), x, y, 60, 60)));
			}
		}
	}
}
void Sudoku::DrawMap()
{
	for (auto& v : rect) 
	{
		v.second->Show();
	}
}

int Sudoku::ClickRect(ExMessage& msg)
{
	for (int i = 0; i < rect.size(); i++) 
	{
		if (rect[i].second->ClickButton(msg) == true)
			return i;
	}
	return -1;
}

void Sudoku::MouseMessage(ExMessage& msg)
{
	int result = ClickRect(msg);
	if (result!=-1&& rect[result].first==true&& MyTimer::Timer(100,1))
	{
		rect[result].second->SetText();
	}
}

bool Sudoku::GameOver()
{
	for (int i = 0; i < map.size(); i++) 
	{
		for (int j = 0; j < map[i].size(); j++) 
		{
			// 纵向检查
			for (int m = 0; m < 9; m++)
			{
				if (m!=i&&map[m][j] == map[i][j])
				{
					return false;
				}
			}
			//横向检查
			for (int n = 0; n < 9; n++) 
			{
				if (n!=j&&map[i][n] == map[i][j]) 
				{
					return false;
				}
			}
			//九宫格检查
			int p = i / 3 * 3;
			int q = j / 3 * 3;
			for (int x = p; x < p + 3; x++)
			{
				for (int y = q; y < q + 3; y++)
				{
					if ((x!=i&&j!=y)&&map[x][y] == map[i][j])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
