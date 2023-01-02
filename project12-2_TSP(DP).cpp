// 출발정점이 1이 아닐때 고려
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<vector<int>> matrix_t;

bool isIn(int i, int A);
int count(int A);
int diff(int A, int j);
int minimum(int n, int i, int &minJ, int A, matrix_t &W, matrix_t &D);
void travel(int n, matrix_t &W, matrix_t &D, matrix_t &P, int &minlength);
void tour(int v, int A, matrix_t &P);

int main(void)
{
    int n; // 정점개수
    int m; // 간성의 개수

    matrix_t K;
    
    cin >> n >> m; //정점의 개수 n과 간선의 개수

    K.resize(n+1,vector<int>(n+1,999999));
    
    int u,v,w;

    for(int i=0; i < m; i++)
    {
        cin >> u >> v >> w;
        K[u][v] = w;
    }
    
    for(int i=0; i<=n; i++)
    {
        K[i][i] = 0; // 정점이 같으면 길이 0임
    }


    matrix_t D;
    matrix_t P;
    
    D.resize(n+1, vector<int>(pow(2,n-1),999999));
    P.resize(n+1, vector<int>(pow(2,n-1),999999));

    int minLen;
    
    travel(n,K,D,P,minLen);
    
    cout << minLen << endl; //최소경로

    cout << "1 "; //경로 출력 1부터 시작
    
    tour(1, pow(2, n - 1) - 1, P); // 경로 출력
    cout << endl;

    for(int i=1; i<n+1; i++)
    {
        for(int j=0; j<pow(2,n-1); j++)
        {
            if(D[i][j]!= 999999) // 무한대가 아닌 2차원 배열(정점들) 출력
            {
                cout<<i<<" "<<j<<" "<<D[i][j]<<endl;
            }
        }
    }
}

bool isIn(int i, int A)
{
    return (A & (1 << (i - 2))) != 0;
}

int count(int A)
{
    int cnt = 0;
    for (; A != 0; A >>= 1)
    {
        if (A & 1)
            cnt++;
    }
    return cnt;
}

int diff(int A, int j)
{
    return (A & ~(1 << (j - 2)));
}

int minimum(int n, int i, int &minJ, int A, matrix_t &W, matrix_t &D)
{
    int minV = 999999;
    
    for (int j = 2; j <= n; j++)
    {
        if (!isIn(j, A))
            continue;
        int value = W[i][j] + D[j][diff(A, j)];
        if (minV > value)
        {
            minV = value;
            minJ = j;
        }
    }
    return minV;
}

void travel(int n, matrix_t &W, matrix_t &D, matrix_t &P, int &minlength)
{
    int i, j, k, A;
    int subset_size = pow(2, n - 1);

    for (i = 2; i <= n; i++)
        D[i][0] = W[i][1];
    
    for (k = 1; k <= n - 2; k++)
    {
        for (A = 0; A < subset_size; A++)
        {
            if (count(A) != k)
            {
                continue;
            }
            for (i = 2; i <= n; i++)
            {
                if (isIn(i, A))
                {
                    continue;
                }
                D[i][A] = minimum(n, i, j, A, W, D); //opt value
                P[i][A] = j; // opt tour
            }
        }
    }

    A = subset_size - 1;
    D[1][A] = minimum(n, 1, j, A, W, D);
    P[1][A] = j;
    minlength = D[1][A];
}

void tour(int v, int A, matrix_t &P)
{
    int k = P[v][A];
    if (A == 0)
        cout << "1";
    else
    {
        cout << k << " ";
        tour(k, diff(A, k), P);
    }
}

