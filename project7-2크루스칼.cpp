#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> dset;

typedef struct edge
{
    int u,v,w;
} edge_t;

struct edge_compare
{
    bool operator()(edge_t e1, edge_t e2)
    {
        if (e1.w > e2.w) return true;
        else return false;
    }
};

typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t,vector<edge_t>, edge_compare> PriorityQueue;


void dset_init(int n)
{
    dset.resize(n + 1);
    for (int i = 1; i <= n; i++)
        dset[i] = i;
}

int dset_find(int i)
{
    while (dset[i] != i)
        i = dset[i];
    return i;
}

void dset_merge(int p, int q)
{
    dset[p] = q;
}

void kruskal(int n, int m, set_of_edges& E, set_of_edges& F);





int main(void)
{
    int n;
    int m;
    cin >> n >> m;
    set_of_edges EDS;
    set_of_edges F;
    int u,v,w;
    for (int i=1;i<=m;i++)
    {
        edge E;
        cin >> u >> v >> w;
        E.u = u;
        E.v = v;
        E.w = w;
        EDS.push_back(E);
    }
    kruskal(n, m, EDS,F);
    for (edge_t edge : F)
        cout << edge.u << " " << edge.v << " " << edge.w << "\n";
    
}




void kruskal(int n, int m, set_of_edges& E, set_of_edges& F)
{
    int p, q;
    edge_t e;
    PriorityQueue PQ;

    // sort the m edges in E by weight in nondecreasing order;
    for (edge_t e: E)
        PQ.push(e);

    F.clear();
    dset_init(n);
    while (F.size() < n - 1)
    {
        e = PQ.top(); PQ.pop(); // edge with least weight not yet considered;
        p = dset_find(e.u);
        q = dset_find(e.v);
        if (p != q)
        {
            dset_merge(p, q);
            F.push_back(e); // add e to F
        }
    }
}