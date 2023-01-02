#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> board;
int cnt = 0;

int whereis(int n,int srow,int scol,int row,int col);
void fill(int n,vector<vector<int>> &board,int srow, int scol, int where);
int holeRow(int part, int where, int n, int srow, int row);
int holeCol(int part, int where, int n, int scol, int col);
void tromino(int n,vector<vector<int>> &board, int srow, int scol, int row, int col);
void resize(int n,vector<vector<int>> &mat);

int main(void)
{
    int r,c,n;
    cin >> n;
    // r,c는 구멍의 좌표
    cin >> r;
    cin >> c;
    
    resize(n, board);
    
    int sr = 0;
    int sc = 0;
    tromino(n, board, sr, sc, r, c);
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (j!= n-1)
                cout << board[i][j] << " ";
            else
                cout << board[i][j];
        }
        cout << "\n";
    }
    
}

int whereis(int n,int srow,int scol,int row,int col)
{
    int m = n/2;
    if (row - srow < m)
    {
        if (col - scol < m)
            return 1;
        else
            return 2;
    }
    else
    {
        if (col - scol < m)
            return 3;
        else
            return 4;
    }
}

void fill(int n,vector<vector<int>> &board,int srow, int scol, int where)
{
    if (where != 1)
    {
        board[srow][scol] = cnt;
    }
    if (where != 2)
    {
        board[srow][scol+1] = cnt;
    }
    if (where != 3)
    {
        board[srow+1][scol] = cnt;
    }
    if (where != 4)
    {
        board[srow+1][scol+1] =cnt;
    }
}

int holeRow(int part, int where, int n, int srow, int row)
{
    int m = n/2;
    if (part!= where)
    {
        row = srow + m -1;
      
        if (part == 3 || part == 4)
        {
            row += 1;
        }
    }
    return row;
}

int holeCol(int part, int where, int n, int scol, int col)
{
    int m = n/2;
    if (part!= where)
    {
        col = scol + m -1;
        if (part == 2 || part == 4)
        {
            col += 1;
        }
    }
    return col;
}
// row랑 col따로 하기 !!!!
void tromino(int n,vector<vector<int>> &board, int srow, int scol, int row, int col)
{
    
    int hrow, hcol;
    cnt++;
    int where1 = whereis(n, srow, scol, row, col);
    if (n==2)
    {
        fill(n,board,srow,scol,where1);
    }
    else
    {
        int m = n/2;
        fill(n,board,srow + m -1, scol +m -1, where1);
        hrow = holeRow(1, where1, n, srow, row);
        hcol = holeCol(1, where1, n, scol, col);
        tromino(m, board, srow, scol, hrow, hcol);
        
        hrow = holeRow(2, where1, n, srow, row);
        hcol = holeCol(2, where1, n, scol, col);
        tromino(m, board, srow, scol+m, hrow, hcol);
        
        hrow = holeRow(3, where1, n, srow, row);
        hcol = holeCol(3, where1, n, scol, col);
        tromino(m, board, srow+m, scol, hrow, hcol);
        
        hrow = holeRow(4, where1, n, srow, row);
        hcol = holeCol(4, where1, n, scol, col);
        tromino(m, board, srow+m, scol+m, hrow, hcol);
    }
    
}

void resize(int n,vector<vector<int>> &mat)
{
   // mat.resize(n,vector<int>(n));
    mat.resize(n,vector<int>(n));
}