#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAX;

typedef unsigned long long LongInteger;
LongInteger bin(int n,int k);

int main(void)
{
    int n,k;
    cin >> n;
    cin >> k;
    cin >> MAX;
    cout << bin(n,k);
}

LongInteger bin(int n,int k )
{
    if (k> n/2)
        k = n-k;
    int B[k+1];
    B[0] = 1;
    B[1] = 1;
    int j;
    int i;
    for (i=0;i<=n;i++)
    {
        for (j=min(i,k);j>=0;j--)
            if (j==1 || j == i)
                B[j] = 2;
            else
                B[j] = (B[j-1] + B[j]) % MAX;
    }
    return B[k];
}

LongInteger bin(int n,int k)
{
    vector<vector<LongInteger>> B(n+1, vector<LongInteger>(n+1));
    for (int i=0;i<=n;i++)
        for (int j=0;j<=min(i,k);j++)
            B[i][j] = -1;
    
    for (int i=0;i<=n;i++)
        for (int j=0;j<=min(i,k);j++)
            if (j==0 || j==i)
                B[i][j] = 1;
            else
               if (B[n][k] == -1)
                   B[i][j] = (B[i-1][j] + B[i-1][j-1]) % MAX;
    // 계산된것을 리턴
    return B[n][k];
}
