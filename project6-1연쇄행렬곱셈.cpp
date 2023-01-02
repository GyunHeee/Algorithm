#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 999999

typedef vector<vector<int>> matrix_t;

void minmult(int n,vector<int> &d, matrix_t &M, matrix_t &P);
int minimum(int i,int j,int &mink, vector<int>& d, matrix_t &M);
void order(int i,int j, matrix_t &P, string &s);

int main(void)
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> d[i];
    matrix_t M, P;
    M.resize(n + 1, vector<int>(n + 1, 0));
    P.resize(n + 1, vector<int>(n + 1, 0));
    minmult(n, d, M, P);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j>=i)
            {
                if (j==n)
                    cout << M[i][j];
                else
                    cout << M[i][j] <<" ";
            }
        }
        cout << "\n";
    }
   
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j>=i)
            {
                if (j==n)
                    cout << P[i][j];
                else
                    cout << P[i][j] <<" ";
            }
        }
        cout << "\n";
    }

    
    cout << M[1][n] << endl;
    string s;
    order(1, n, P, s);
    cout << s << endl;
    
}

void minmult(int n,vector<int> &d, matrix_t &M, matrix_t &P)
{
    for (int i=1;i<=n;i++)
    {
        M[i][i] = 0;
    }
    for (int diagonal = 1; diagonal <= n-1; diagonal++)
        for (int i=1;i<=n-diagonal;i++)
        {
            int j= i+diagonal;
            int k;
            M[i][j] = minimum(i, j, k, d, M);
            P[i][j] = k;
        }
}

int minimum(int i,int j,int &mink, vector<int>& d, matrix_t &M)
{
    int minValue = INF;
    int value;
    for (int k=i;k<=j-1;k++)
    {
        value = M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];
        if (minValue > value)
        {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void order(int i,int j, matrix_t &P, string &s)
{
    if (i == j)
        s+= string("(A") + to_string(i) + string(")");
    else
    {
        int k= P[i][j];
        s += string("(");
        order(i,k,P,s);
        order(k+1,j,P,s);
        s += string(")");
    }
}