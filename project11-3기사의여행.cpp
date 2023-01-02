#include <iostream>
#include <vector>
#include <algorithm>

// 해밀턴 회로는 출발 정점과 무관하게 회로의 수를 구할 수 있습니다.
// 해밀턴 경로는 출발 정점에 따라 가능한 경로의 수가 달라짐에 유의

using namespace std;

int n, m, T, s;
int cnt;
int circleCnt;

vector<vector<int>> graph;
vector<int> mark;

void make_graph()
{
    int imov[] = { -2,-1,1,2,2,1,-1,-2 };
    int jmov[] = { 1,2,2,1,-1,-2,-2,-1 };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 8; k++) // 방향 8개
            {
                int ni = i + imov[k];
                int nj = j + jmov[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                {
                    graph[i * m + j].push_back(ni * m + nj);
                }
            }
        }
    }
}


void tour(int k, int v)
{
    if (k == n * m)
    {
        mark[v] = k;
        cnt++;
    }
    else {
        for (int i : graph[v])
        {
            if (mark[i] == 0)
            {
                mark[i] = k + 1;
                tour(k + 1, i);
                mark[i] = 0;
            }
        }
    }
}


void circle(int k, int v)
{
    if (k == n * m)
    {
        for (int i = 0; i < graph[v].size(); i++)
        {
            if (s == graph[v][i])
            {
                mark[v] = k;
                circleCnt++;
            }
        }
    }
    else
    {
        for (int i : graph[v])
        {
            if (mark[i] == 0) //방문 하지 않은 vertex
            {
                mark[i] = k + 1;
                circle(k + 1, i);
                mark[i] = 0; // 함수가 끝일때 0으로 초기화 하면 모든 정점 방문함
            }
        }
    }
}

int main()
{
    cin >> n >> m; // 행,열
    
    graph.resize(n * m, vector<int>(0));
    mark.resize(n * m, 0);
    make_graph();
    
    cin >> T; // 출발정점의 개수
    
    circle(1, 0);
    cout << circleCnt << endl; //해밀턴 회로 갯수
    
    for (int k = 0; k < T; k++)
    {
        int i = 0;
        int j = 0;
        cin >> i >> j; // 출발정점이 i(row),j(col)의 쌍으로 주어진다.
        s = i * m + j;
        mark[s] = 1;
        tour(1, s);
        cout << cnt << endl; //해밀턴 경로의 수를 하나씩 출력
        cnt = 0;
        mark.assign(n*m,0); 
    }
}