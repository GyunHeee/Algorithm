#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int k;
int m;
vector<vector<int>> w;
vector<int> vcolor;

int cnt;

bool promising(int i);
void m_coloring(int i);

int main(void)
{
    cin >> n >> k; // 정점의 수 n과 간선의 수 k가 주어진다.
    w.resize(n+1,vector<int>(n+1));
    vcolor.resize(n+1);
    
    for (int i=1;i<=k;i++)
    {
        int u,v;
        cin >> u >> v; // k개의 간선의 수가 주어짐
        w[u][v] = w[v][u] = 1; // undirected graph
    }
    // m을 출력, m갑ㅅ으로 색칠할 수 있는 경우의 수를 출력.
    for(m=1; m<=n;m++)
    {
          m_coloring(0);
          if(cnt!=0) break;
    }
    
    cout << m << endl; //색칠 가능한 최소의 m값
    cout << cnt; // m값으로 색칠할 수 있는 경우의 수
    
}

bool promising(int i)
{
    int j = 1;
    bool flag = true;
    
    while (j<i && flag)
    {
        if (w[i][j] && vcolor[i] == vcolor[j])
        {
            flag = false;
        }
        j++;
    }
    return flag;
}

void m_coloring(int i)
{
    int color;
    
    if (promising(i))
    {
        if (i== n)
        {
            cnt++;
        }
        else
            for (color = 1; color <=m; color++)
            {
                vcolor[i+1] = color;
                m_coloring(i+1);
            }
    }
}