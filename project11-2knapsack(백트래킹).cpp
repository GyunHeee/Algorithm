#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <array>

// 상태공간 트리의 각 노드에서 출력 + 최대 이익 출력
// 상태공간 트리 그릴 때 레벨이 같을 때는 무조건 왼쪽이 먼저 출력됨
 
using namespace std;

int maxprofit;
int n;
int W;
int num;

float bound;

vector<int> include;
vector<int> bestset;
vector<int> w;
vector<int> p;

bool promising(int i,int profit, int weight);
void knapsack4(int i, int profit, int weight);

int main(void)
{
    cin >> n >> W; // 아이템의 개수 n과 배낭의 무게 W
    
    w.resize(n+1);
    p.resize(n+1);
    
    for (int i=1;i<=n;i++)
    {
        cin >> w[i]; // n개의 아이템 무게 w[i]가 주어진다.
    }
    
    for (int i=1;i<=n;i++)
    {
        cin >> p[i]; // n개의 아이템 이익 p[i]가 주어진다.
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
    
    include.resize(n + 1, 0);
    knapsack4(0, 0, 0);
    
    cout << maxprofit << endl; // 최대 이익을 출력
    
    for (int i=1;i<=n;i++)
    {
        if (bestset[i])
            cout << w[i] << " " << p[i] << endl; //배낭에 담은 아이템
    }
}

bool promising(int i,int profit, int weight)
{
    int j,k,totweight;
    //if문안의 cout 출력하기 위해서 bound 전역으로 선언
    if (weight >= W)
    {
        cout << i <<" " << weight <<" " << profit<< " " << bound <<" "<< maxprofit << endl;
        return false;
    }
    else
    {
        j = i+1;
        bound = profit;
        totweight = weight;
        while (j<=n && totweight + w[j] <= W)
        {
            totweight += w[j];
            bound += p[j];
            j++;
        }
        k = j;
        if (k<=n)
            bound += (W-totweight) * ((float)p[k] / w[k]); //한 줄에 하나씩 상태공간트리를 방문하는 노드의 상태를 출력하시오.
        cout << i <<" " << weight <<" " << profit<< " " << bound <<" "<< maxprofit << endl;
        return bound > maxprofit; //다음과 같이 출력 i weight profit bound maxprofit
    }
}

void knapsack4(int i, int profit, int weight)
{
    if (weight <= W && profit > maxprofit)
    {
        maxprofit = profit;
        bestset.resize(include.size());
        copy(include.begin(), include.end(), bestset.begin());
        num = i;
    }

    if (i <= n && promising(i, profit, weight))
    {
        include[i + 1] = 1;
        knapsack4(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = 0;
        knapsack4(i + 1, profit, weight);
    }
    
}