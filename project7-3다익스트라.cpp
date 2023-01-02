#include <iostream>
#include <algorithm>
#include <vector>

#define INF 0xffff

using namespace std;

vector<int> touch;

typedef vector<vector<int>> matrix_t;;
typedef vector<pair<int,int>> set_of_edges;

void dijkstra(int n, matrix_t& W, set_of_edges& F);
void path(int i);
int main(void)
{
    int n;
    int m;
    cin >> n >> m;
    touch.resize(n+1);
    matrix_t W;
    W.resize(n+1,vector<int>(n+1,INF));
    
    for (int i=0;i<=n;i++)
    {
        W[i][i] = 0;
    }
    
    int u,v,w;
    
    for (int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        W[u][v] = w;
    }
    
    set_of_edges F;
    dijkstra(n, W, F);
    for (auto e: F)
    {
        u = e.first; v = e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }
    
    int T,y;
    cin>>T;
    while(T--)
    {
        cin>>y;
        path(y);
        cout<<y<<endl;
    }
     
}

void dijkstra(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> length(n+1);
    
    
    F.clear();
    for (int i = 2; i <= n; i++)
    {
        touch[i] = 1;
        length[i] = W[1][i];
    }
    
    for (int i=2;i<=n;i++)
    {
        if (i==n)
        {
            cout << touch[i];
        }
        else
        {
            cout << touch[i] << " ";
        }
    }
    cout << "\n";
    
    for (int k = 1; k <= n - 1; k++)
    {
        min = INF;
        for (int i = 2; i <= n; i++)
        {
            if (0 <= length[i] && length[i] < min)
            {
                min = length[i];
                vnear = i;
            }
        }
        F.push_back(make_pair(touch[vnear], vnear));
        
        for (int i = 2; i <= n; i++)
        {
            if (length[i] > length[vnear] + W[vnear][i])
            {
                length[i] = length[vnear] + W[vnear][i]; // 1에서 한번에 가는 vertex의 가중치와
                // 1에서 다른곳을 거쳐서 가는 곳들의 값을 비교, 후자가 더 크면 length배열에 후자의 값을 대입
                touch[i] = vnear;
            }
        }
        
        // touch[4] == 5  touch[5] == 1
        
        length[vnear] = -1;
        for (int i=2;i<=n;i++)
        {
            if (i!= n)
                cout << touch[i] << " ";
            else
                cout << touch[i];
            if (i % n== 0)
                cout << "\n";
        }
    }
     
    // 1과 인접한 vertex중 가장 짧은것이 vnear
    // e = edge from vertex indexed by touch[vnear];
    // add e to F;
    // vnear값을 배열에 대입
 
    
    
}
void path(int i)
{
    if(touch[i]==1)
    {
        cout<<touch[i]<<" ";
        return;
    }
    else{
        path(touch[i]);
    }
    cout<<touch[i]<<" ";
}