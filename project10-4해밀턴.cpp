#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vindex;
vector<vector<int>> W;
int cnt;

bool promising(int i);
void hamiltonian(int i);

int main(void)
{
    int m;
    cin >> n >> m; // 정점의 개수 n과 간석의 개수 m
    int u, v;
    
    W.resize(n+1, vector<int>(n+1));
    
    for (int i=1; i<= m; i++)
    {
        cin >> u >> v; // m개의 간선
        W[u][v] = W[v][u] = 1;
    }
    
    vindex.resize(n+1);
    vindex[0] = 1; //v1이 출발정점이라는 뜻임. 기말에는 다른 vertex가 출발정점일 수 있음
    hamiltonian(0);
    
    cout << cnt; //해밀턴 회로의 개수를 출력
    
}

bool promising(int i)
{
    int j;
    bool flag;
    if (i == n-1 && !W[vindex[n - 1]][vindex[0]])
        flag = false;
    else if (i>0 && !W[vindex[i - 1]][vindex[i]])
        flag = false;
    else
    {
        flag = true;
        j = 1;
        while (j < i && flag)
        {
            if (vindex[i] == vindex[j])
                flag = false; // 이미 방문한 노드이면 false
            j++;
        }
    }
    return flag;
}

void hamiltonian(int i)
{
    int j;
    
    if (promising(i))
    {
        if (i== n-1)
            cnt++;
        else
            for (j = 2; j<=n; j++)
            {
                vindex[i+1] = j;
                hamiltonian(i+1);
            }
    }
}