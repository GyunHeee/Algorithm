#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef struct item *item_ptr;
typedef struct item
{
    int id;
    int weight;
    int profit;
    int profit_per_unit; // profit / weight
} item_t;


typedef pair<int, int> edge_t;
typedef vector<pair<int, int>> set_of_edges;

int n, W;
vector<item_t> items;

bool compare_item(item_t i, item_t j);
void knapsack1(int & maxprofit, int & totweight,int n, set_of_edges &E);

int main()
{
    cin >> n; // 아이템의 개수 n
    
    items.resize(n + 1);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i].weight; // n개의 아이템의 무게
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i].profit; // n개의 아이템별 이익
    }
    
    for (int i = 1; i <= n; i++)
    {
        items[i].id = i;
        items[i].profit_per_unit = items[i].profit / items[i].weight;
    }
    
    sort(items.begin() + 1, items.end(), compare_item); // 내림차순 정렬

    int T;
    cin >> T; // 도둑 배낭의 개수
    
    int maxprofit, totweight;
    set_of_edges E;
    
    while (T>0)
    {
        T--;
        cin >> W; // 도둑 배낭의 무게
        knapsack1(maxprofit,totweight,n,E);
        cout << maxprofit<<endl; // 배낭에 담을 수 있는 최대 이익 출력
        for(int i=0;i<E.size();i++)
        {
            cout <<E[i].second<<" "<<E[i].first<<endl; // 배낭에 담은 아이템의 순서대로 무게와 이익의 쌍을 한 줄에 하나씩 출력
        } // 마지막은 분할한 무게와 이익을 출력함
    }

    
}

bool compare_item(item_t i, item_t j)
{
    if (i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
}

void knapsack1(int& maxprofit, int& totweight,int n,set_of_edges& E)
{
    maxprofit=totweight=0;
    edge_t a;
    E.clear();
    int n1,n2;
    for(int i=1;i<=n;i++)
    {
        if(totweight+items[i].weight<W)
        {
            maxprofit+=items[i].profit;
            totweight+=items[i].weight;
            a=make_pair(items[i].profit,items[i].weight);
            E.push_back(a);
        }
        else if(totweight+items[i].weight<W)
            break;
        else
        {
            maxprofit+=(W-totweight)*items[i].profit_per_unit;
            n1=(W-totweight);
            n2=(W-totweight)*items[i].profit_per_unit;
            a=make_pair(n2,n1);
            E.push_back(a);
            totweight+=(W-totweight);
            break;
        }
    }
}