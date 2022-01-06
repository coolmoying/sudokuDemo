#include "autosudoku.h"
Autosudoku::Autosudoku(array<array<int, 9>, 9>& data)
{
    for (int i = 0; i < data.size(); i++) 
    {
        for (int j = 0; j < data[i].size(); j++) 
        {
            board[i][j] = data[i][j];
        }
    }
}
int* Autosudoku::GetNextSpace(int board[][9], int rowStart, int colStart)
{
    if (colStart > 8) {
        rowStart++;
        colStart = 0;
    }
    if (rowStart > 8) {
        return new int[] {-1};
    }
    for (int j = colStart; j < 9; j++) {
        if (board[rowStart][j] == 0) {
            return new int[] {rowStart, j};
        }
    }
    rowStart++;
    if (rowStart > 8)
    {
        return new int[] {-1};
    }
    for (int i = rowStart; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                return new int[] {i, j};
            }
        }
    }
    return new int[] {-1};
}
bool Autosudoku::ValidateBoard(int board[][9], int i, int j, int k)
{
    // ������
    for (int m = 0; m < 9; m++) 
    {
        if (board[m][j] == k) 
        {
            return false;
        }
    }
    //������
    for (int n = 0; n < 9; n++) 
    {
        if (board[i][n] == k) 
        {
            return false;
        }
    }
    //�Ź�����
    int p = i / 3 * 3;
    int q = j / 3 * 3;
    for (int x = p; x < p + 3; x++)
        for (int y = q; y < q + 3; y++)
        {
            if (board[x][y] == k) {
                return false;
            }
        }
    return true;
}
void Autosudoku::GetResult(int board[][9], int i, int j)
{
    //�����ո�Ѱ����һ���ո�
    int* next = GetNextSpace(board, i, j);
    if (next[0] == -1)
    {
        return;
    }
    int m = next[0];
    int n = next[1];
    //ÿ���ո��д�1-9��ȡֵ����
    for (char k = 1; k <= 9; k++) {
        //��֤�Ƿ����Ҫ��
        if (ValidateBoard(board, m, n, k)) {
            board[m][n] = k;
            //������һ��ݹ�
            GetResult(board, m, n + 1);
            //����ʱ���ûؿո�
            board[m][n] = 0;
        }
    }
}

