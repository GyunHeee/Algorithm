#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node node_t;
struct node {
    int level;
    int profit;
    int weight;
};

typedef queue<node_t> queue_of_node;

int n, W;
vector<int> p, w;

int bound(node_t u)
{
    if (u.weight >= W)
        return 0;
    else {
        int result = u.profit;
        int j = u.level + 1;
        int totweight = u.weight;
        while (j <= n && totweight + w[j] <= W) {
            totweight += w[j];
            result += p[j];
            j++;
        }
        int k = j;
        if (k <= n)
            result += (W - totweight) * p[k] / w[k];
        return result;
    }
}

void knapsack2(int& maxprofit) {
    queue_of_node Q;
    maxprofit = 0;
    node_t v;
    v.level = 0; v.profit = 0; v.weight = 0;
    Q.push(v);
    cout << v.level << " " << v.weight << " " << v.profit << " " << bound(v) << endl;
    
    while (!Q.empty()) {
        node_t v = Q.front(); Q.pop();
        node_t u1;
        u1.level = v.level + 1;
        u1.weight = v.weight + w[u1.level];
        u1.profit = v.profit + p[u1.level];
        if (u1.weight <= W && u1.profit > maxprofit)
            maxprofit = u1.profit;
        if (bound(u1) > maxprofit)
            Q.push(u1);
        node_t u2;
        u2.level = v.level + 1;
        u2.weight = v.weight;
        u2.profit = v.profit;
        if (bound(u2) > maxprofit)
            Q.push(u2);
        cout << u1.level << " " << u1.weight << " " << u1.profit << " " << bound(u1) << endl; // 방문노드 출력
        cout << u2.level << " " << u2.weight << " " << u2.profit << " " << bound(u2) << endl;
    }
}

int main()
{
    cin >> n; // 아이템의 개수
    w.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i]; // n개의 아이템의 무게
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i]; // n개의 아이템의 이익
    
    int tmpP;
    int tmpW;
    
    vector<int> profitPerweight;
    profitPerweight.resize(n+1);
    
    for (int i=1;i<=n;i++)
    {
        profitPerweight[i] = (p[i] / w[i]);
        for (int j=i+1;j<=n;j++)
        {
            profitPerweight[j] = p[j] / w[j];
            if (profitPerweight[i] < profitPerweight[j])
            {
                tmpW = w[i];
                w[i] = w[j];
                w[j] = tmpW;
                tmpP = p[i];
                p[i] = p[j];
                p[j] = tmpP;
            }
        }
    }

    int T;
    cin >> T; // 배낭의 개수
    while (T-- > 0) {
        cin >> W; // 배낭의 무게
        int maxprofit;
        knapsack2(maxprofit);
        cout << maxprofit << endl;
    }
}