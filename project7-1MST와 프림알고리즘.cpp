#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0xffff


using namespace std;

typedef vector<vector<int>> matrix_t;
typedef pair<int, int> edge_t;
typedef vector<pair<int,int>> set_of_edges;


void prim(int n, matrix_t& W, set_of_edges& F);

int main(void)
{
    int n;
    int m;
    int u, v, w;
    cin >> n >> m;
    matrix_t path;
    path.resize(n+1,vector<int>(n+1,INF));
    for (int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        path[u][v] = path[v][u] = w;
    }
    
    
    set_of_edges F;
    prim(n, path, F);
    
    for (edge_t e: F)
    {
        u = e.first; v = e.second;
        cout << u << " " << v << " " << path[u][v] << "\n";
    }
}

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n+1);
    vector<int> distance(n+1);
    
    F.clear(); // F = 공집합
    for (int i = 2; i <= n; i++)
    {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }
    for (int i=2;i<=n;i++)
    {
        if (i==n)
        {
            cout << nearest[i];
        }
        else
        {
            cout << nearest[i] << " ";
        }
    }
    cout << "\n";

    for (int i= 1; i<= n-1; i++)
    {
        min = INF;
        for (int j = 2; j <= n; j++)
            if (0 <= distance[j] && distance[j] < min)
            {
                min = distance[j];
                vnear = j;
            }

        F.push_back(make_pair(vnear, nearest[vnear]));
        
        
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++)
        {
            if (distance[i] > W[i][vnear])
            {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
        for (int i=2;i<=n;i++)
        {
            if (i!= n)
                cout << nearest[i] << " ";
            else
                cout << nearest[i];
            if (i % n== 0)
                cout << "\n";
        }
    }
}