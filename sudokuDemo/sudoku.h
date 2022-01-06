#pragma once
#include "common.h"
class Button;
class Sudoku
{
public:
    Sudoku();
    void DrawMap();
    int ClickRect(ExMessage& msg);
    void MouseMessage(ExMessage& msg);
    bool GameOver();
protected:
    array<array<int, 9>,9> map = 
    {
        3, 0, 6, 4, 5, 1, 8, 7, 9 ,
        0, 4, 5, 7, 0, 9, 2, 0, 0 ,
        7, 0, 9, 2, 0, 0, 1, 4, 5 ,
        0, 0, 3, 5, 4, 7, 6, 9, 0 ,
        0, 0, 0, 0, 9, 0, 0, 1, 2 ,
        6, 0, 8, 0, 2, 3, 4, 0, 0 ,
        5, 0, 1, 0, 0, 2, 9, 6, 4 ,
        8, 6, 4, 0, 0, 5, 7, 2, 3 ,
        9, 7, 2, 3, 6, 4, 0, 8, 0 
    };

    //³É¹¦µØÍ¼
    //array<array<int, 9>, 9> map =
    //{
    //      3,2,6,4,5,1,8,7,9,
    //      1,4,5,7,8,9,2,3,6,
    //      7,8,9,2,3,6,1,4,5,
    //      2,1,3,5,4,7,6,9,8,
    //      4,5,7,6,9,8,3,1,2,
    //      6,9,8,1,2,3,4,5,7,
    //      5,3,1,8,7,2,9,6,4,
    //      8,6,4,9,1,5,7,2,3,
    //      9,7,2,3,6,4,5,8,1
    //};
    vector<pair<bool, Button*>> rect;
};