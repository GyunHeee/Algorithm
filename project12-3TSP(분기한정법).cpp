#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;

typedef vector<int> ordered_set;
vector<vector<int>> W;

int n;

typedef struct node node_t;
struct node
{
    int level;
    int bound;
    vector<int> path;
};

struct node_compare {
    bool operator()(node_t u, node_t v) {
        if (u.bound > v.bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_t, vector<node_t>, node_compare> priority_queue_of_node;

int length(vector<int> path);
bool hasOutgoing(int v, vector<int>& path);
bool hasIncoming(int v, vector<int>& path);

int length(vector<int> path)
{
    int len = 0;
    for (int i = 0; i < path.size() - 1; i++)
        len += W[path[i]][path[i + 1]];
    return len;
}

bool hasOutgoing(int v, vector<int>& path)
{
    for (int i = 0; i < path.size() - 1; i++)
        if (v == path[i]) return true;
    return false;
}

bool hasIncoming(int v, vector<int>& path)
{
    for (int i = 1; i < path.size(); i++)
        if (v == path[i]) return true;
    return false;
}

int bound(node_t u)
{
    int lowerbound = length(u.path);
    for (int i = 1; i <= n; i++) {
        if (hasOutgoing(i, u.path)) continue;
        int min = 999999;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (hasIncoming(j, u.path)) continue;
            if (j == 1 && i == u.path[u.path.size() - 1]) continue;
            if (min > W[i][j]) min = W[i][j];
        }
        lowerbound += min;
    }
    return lowerbound;
}

int remaining(vector<int> path)
{
    int s = 0;
    for (int i : path)
        s += i;
    return n * (n + 1) / 2 - s;
}

bool isIn(int v, vector<int> path)
{
    for (int i = 0; i < path.size(); i++)
        if (v == path[i]) return true;
    return false;
}

void travel2(vector<int>& opttour, int& minlength)
{
    priority_queue_of_node PQ;
    minlength = 999999;
    node_t v;
    v.level = 0; v.path.push_back(1); v.bound = bound(v);
    PQ.push(v);
    cout << v.level << " " << v.bound << " ";
    for (int i = 0;i < v.path.size();i++)
        cout << v.path[i] << endl;
    while (!PQ.empty())
    {
        node_t v = PQ.top(); PQ.pop();
        if (v.bound < minlength) {
            for (int i = 2; i <= n; i++)
            {
                if (isIn(i, v.path)) continue;
                node_t u;
                u.level = v.level + 1;
                u.path.resize(v.path.size());
                copy(v.path.begin(), v.path.end(), u.path.begin());
                u.path.push_back(i);
                if (u.level == n - 2)
                {
                    u.bound = bound(u);
                    u.path.push_back(remaining(u.path));
                    u.path.push_back(1);
                    if (length(u.path) < minlength) {
                        minlength = length(u.path);
                        opttour.resize(u.path.size());
                        copy(u.path.begin(), u.path.end(), opttour.begin());
                    }
                   
                }
                else
                {
                    u.bound = bound(u);
                    if (u.bound < minlength)
                        PQ.push(u);
                    
                }
                if (u.bound >= 999999) {
                    cout << u.level << " " << "INF" << " ";
                }
                else cout << u.level << " " << u.bound << " ";//분기한정법으로 방문하는 노드의 상태를 출력
                // level bound path[0] path[1] ...... path[k]
    
                for (int i = 0;i < u.path.size();i++)
                     cout << u.path[i] << " ";
                cout << endl;
            }
        }
    }
}

int main(void)
{
    int m;
    int u, v, w;
    int min;
    cin >> n >> m; // 정점의 개수 n, 간선의 개수 m
    W.resize(n + 1, vector<int>(n + 1, 999999));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    for (int i = 1;i <= m;i++)
    {
        cin >> u >> v >> w; // m개의 간선이 u,v,w의 형태로 주어진다.
        W[u][v] = w;
    }

    vector<int> tour;
    travel2(tour, min);
    cout << min << endl; // minlength값 출력
    
    for (int i = 0; i < tour.size(); i++)
    {
        if (i != tour.size() - 1)
            cout << tour[i] << " "; // 최적 순회 경로 출력
        else
            cout << tour[i] << endl;
    }
}