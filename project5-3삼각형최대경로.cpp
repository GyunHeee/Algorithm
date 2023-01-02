#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tri, cost, path;
int Max = 999;
// 배열 설정
// c(row,col) = T[row][col] + max(c[row+1][col], c[row+1][col+1]);
// 재귀 --> 시간 초과
// memoization

int pascal(int row,int col, vector<vector<int>> &t, vector<vector<int>> &cost);

int main(void)
{
    int n;
    cin >> n;
    
    tri.resize(n+1, vector<int>(n+1));
    cost.resize(n+1,vector<int>(n+1));
    path.resize(n+1,vector<int> (n+1));
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i+1;j++)
            cost[i][j] = Max;
    }
    
    for (int i=0;i<n;i++)
        for (int j=0;j<i+1;j++)
            path[i][j] = -1;
    
    for (int i=0;i<n;i++)
        for (int j=0;j<i+1;j++)
            tri[i][j] = -1;
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i+1;j++)
        {
            cin >> tri[i][j];
        }
    }
    
    
    int sum = 0;
    sum = pascal(0,0,tri,cost);
    
    
    for (int i=n-1;i>=0;i--)
    {
        for (int j=0;j<i+1;j++)
        {
            if (cost[i+1][j]> cost[i+1][j+1]) //여기에 등호 붙이면 왼쪽부터 출력됨
                path[i][j] = 0;
            else
                path[i][j] = 1;
        }
    }
    
    cout << sum << endl;
    
    int j = 0;
       for (int i = 0; i < n; i++) {
          if(i==n-1) cout << tri[i][j];
          else cout << tri[i][j] << " ";
          if (path[i][j] == 0) {
             j = j;
          }
          else {
             j = j+1;
          }
       }
}

int pascal(int row,int col, vector<vector<int>> &t, vector<vector<int>> &cost)
{
    
    if (row == t.size())
        return 0;
    
    if (cost[row][col]==Max)
    {
        cost[row][col] = t[row][col] + max(pascal(row+1,col,tri, cost), pascal(row+1,col+1,tri,cost));
    }
    
    return cost[row][col];
}