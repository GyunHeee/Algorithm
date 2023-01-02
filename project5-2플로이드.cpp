#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999

typedef vector<vector<int>> matrix_t;
matrix_t W, D, P;

void floyd(int n,matrix_t &W, matrix_t &D, matrix_t &P);
void path(matrix_t &P,int u, int v, vector<int> &p);

int main(void)
{
    int N;
    int M;
    cin >> N >> M;
    int u,v,w;
    
    W.resize(N+1,vector<int>(N+1));
    D.resize(N+1,vector<int>(N+1));
    P.resize(N+1,vector<int>(N+1));
 
    for(int i=1;i<=N;i++)
    {
           for(int j=1;j<=N;j++)
           {
               if(i==j)
               W[i][j]=0;
               else
               W[i][j]=INF;
           }
       }
    
    for(int i=0;i<M;i++)
    {
        cin >> u >> v >>w;
        W[u][v]= w;
    }
    
    floyd(N,W,D,P);
    
    int T;
    cin>> T;
    
    int row,col;
    
    
    for (int i=1;i<=N;i++)
    {
           for(int j=1; j<=N;j++)
           {
               if (j!= N)
                   cout << D[i][j] << " ";
               else
                   cout << D[i][j];
           }
           cout << endl;
    }

    for (int i=1;i<=N;i++)
    {
           for(int j=1; j<=N;j++)
           {
               if (j!= N)
                   cout << P[i][j] << " ";
               else
                   cout << P[i][j];
           }
           cout << endl;
    }
    
    for (int i=0;i<T;i++)
    {
        vector<int> pa;
        cin >> row >> col;
        path(P,row,col,pa);
        
        if (D[row][col] == 999)
        {
            cout << "NONE";
            cout << endl;
            continue;
        }
        
        cout<<row << " ";
        
        for(int i =0;i<pa.size();i++)
        {
            cout<<pa[i]<<" "; // 거쳐서 간 곳
        }
        cout<<col;
        cout<< endl;
    }
    
}


void floyd(int n,matrix_t &W, matrix_t &D, matrix_t &P)
{
    for (int i=1;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
}

void path(matrix_t &P,int u, int v, vector<int> &p)
{
    int k = P[u][v];
    if (k!= 0)
    {
        path(P,u,k,p); // u--> k로
        p.push_back(k); // 중간지점 저장
        path(P,k,v,p); //k--> v로
    }
}
