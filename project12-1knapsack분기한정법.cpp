#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int W;
vector<int> w;
vector<int> p;

typedef struct node *node_pointer;
typedef struct node
{
    int level;
    int weight;
    int profit;
    float bound;
}nodetype;

struct compare
{
    bool operator()(node_pointer u , node_pointer v)
    {
        if (u->bound < v->bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_pointer,vector<node_pointer>, compare> priority_queue_of_node;

void knapsack6(int &maxprofit);
float bound(node_pointer u);

node_pointer create_node(int level, int weight, int profit)
{
    node_pointer v = (node_pointer)malloc(sizeof(nodetype));
    v->level = level;
    v->weight = weight;
    v->profit = profit;
    v->bound = bound(v);
    return v;
}

int main(void)
{
    cin >> n >> W; // 아이템개수와 배낭의 무게
    
    w.resize(n+1);
    p.resize(n+1);
    
    for (int i=1;i<=n;i++)
    {
        cin >> w[i]; // n개의 아이템 무게
    }
    
    for (int i=1;i<=n;i++)
    {
        cin >> p[i]; // n개의 아이템의 이익
    }
    
    
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
    
    int maxprofit;
    
    knapsack6(maxprofit); // 방문한 노드의 개수도 파악가능
    
    cout << maxprofit;
}

float bound(node_pointer u)
{
    float result;
    if (u->weight >= W)
        return 0;
    else
    {
        result = u->profit;
        int j = u-> level + 1;
        int totweight = u-> weight;
        while (j <= n && totweight + w[j] <= W)
        {
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

void knapsack6(int &maxprofit)
{
    priority_queue_of_node PQ;
    node_pointer v;
    maxprofit = 0;
    v = create_node(0, 0, 0);
    v->bound = bound(v);
    PQ.push(v);
    cout << v->level << " " << v->weight << " " << v-> profit <<" " << v->bound << endl;
    while (!PQ.empty())
    {
        v = PQ.top();
        PQ.pop();
        if (v->bound > maxprofit)
        {
            node_pointer u1;
            u1 = create_node(v->level+1, v->weight+w[v->level+1], v->profit + p[v->level+1]);
            if (u1->weight <= W && u1->profit > maxprofit)
                maxprofit = u1->profit;
            if (u1->bound > maxprofit)
                PQ.push(u1);
            node_pointer u2;
            u2 = create_node(v->level + 1, v->weight, v->profit);
            if (u2->bound > maxprofit)
                PQ.push(u2);
            //방문노드 출력
            cout << u1->level << " " << u1->weight << " " << u1-> profit <<" " << u1->bound << endl;
            cout << u2->level << " " << u2->weight << " " << u2-> profit <<" " << u2->bound << endl;
        }
    }
}
