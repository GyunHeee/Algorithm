#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int knapsack3(int n, int W, vector<int> w, vector<int> p, map<pair<int,int>,int> &P);

int main(void)
{
    int n;
    cin >> n; // 아이템수 n개
    
    vector<int> w;
    vector<int> p;
    map<pair<int,int>,int> P;
    
    int T, W;
    
    w.resize(n+1);
    p.resize(n+1);
    
    
    for (int i=1;i<=n;i++)
    {
        cin >> w[i]; // n개의 무게 w[i]가 주어진다.
    }
        
    for (int i=1;i<=n;i++)
    {
        cin >> p[i]; //n개의 이익 p[i]가 주어진다.
    }
        
    int tmpP; // 정렬
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

    cin >> T; //배낭의 개수
    
    for (T;T>0;T--)
    {
        cin >> W; //배낭 무게 W가 주어진다.
        int maxprofit = knapsack3(n, W, w, p, P); // 최대 이익 출력
        cout << maxprofit << endl;
        map<pair<int, int>, int>::iterator e; //
        for (e = P.begin(); e != P.end(); e++)
        {
            cout << e->first.first << " "; // 실행과정에서 결과 테이블 P에 저장한
            cout << e->first.second << " "; // 무게(i) 또는 이익(j)이 0이 아닌 모든 항목
            cout << e->second << endl; // P[i][j]를, (i,j)의 오름차순으로 모두 출력
        }
        P.clear();
    }
}

int knapsack3(int n, int W, vector<int> w, vector<int> p, map<pair<int, int>, int> &P)
{
    if (n == 0 || W <= 0)
        return 0;
    int lvalue = (P.find(make_pair(n-1, W)) != P.end()) ?
        P[make_pair(n-1, W)] : knapsack3(n-1, W, w, p, P);
    int rvalue = (P.find(make_pair(n-1, W-w[n])) != P.end()) ?
        P[make_pair(n-1, W)] : knapsack3(n-1, W-w[n], w, p, P);
    P[make_pair(n, W)] = (w[n] > W) ? lvalue : max(lvalue, p[n] + rvalue);
    return P[make_pair(n, W)];
}