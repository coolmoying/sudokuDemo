#include <iostream>
#include <ctime>
using namespace std;
int* getNextSpace  (int board[][9],int rowStart, int colStart) 
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
bool validateBoard (int board[][9] ,int i,int j, int k) 
{
    // ������
    for (int m = 0; m < 9; m++) {
        if (board[m][j] == k) {
            return false;
        }
    }
    //������
    for (int n = 0; n < 9; n++) {
        if (board[i][n] == k) {
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
void printResult   (int result[][9] )
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}
void solveShuDu    (int board[][9], int i, int j) 
{
    //�����ո�Ѱ����һ���ո�
    int* next = getNextSpace(board, i, j);
    if (next[0] == -1) {
        //�ҵ�������һ��������ʹ�ӡ����
        printResult(board);
        return;
    }
    int m = next[0];
    int n = next[1];
    //ÿ���ո��д�1-9��ȡֵ����
    for (char k = 1; k <=9; k++) {
        //��֤�Ƿ����Ҫ��
        if (validateBoard(board, m, n, k)) {
            board[m][n] = k;
            //������һ��ݹ�
            solveShuDu(board, m, n + 1);
            //����ʱ���ûؿո�
            board[m][n] = 0;
        }
    }

}

int main()
{
    int start = clock();
    int board[][9] =
    {
        3,0,6,4,5,1,8,7,9,
        0,4,5,7,0,9,2,0,0,
        7,0,9,2,0,0,1,4,5,
        0,0,3,5,4,7,6,9,0,
        0,0,0,0,9,0,0,1,2,
        6,0,8,0,2,3,4,0,0,
        5,0,1,0,0,2,9,6,4,
        8,6,4,0,0,5,7,2,3,
        9,7,2,3,6,4,0,8,0
    };
    solveShuDu(board, 0, 0);
    int end = clock();
    cout <<"time:" << end - start << endl;
    return 0;
}