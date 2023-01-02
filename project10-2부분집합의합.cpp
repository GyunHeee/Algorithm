#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int W;
int n;
vector<int> w;
vector<int> include;


int cnt;

bool promising(int i, int weight, int total);
void sum_of_subsets1(int i, int weight, int total);
void sum_of_subsets2(int i, int weight, int total);

int main(void)
{
    cin >> n; // 원소개수 n개
    cin >> W; // 합이 W
    
    
    w.resize(n+1);
    include.resize(n+1);
    
    for (int i=1;i<=n;i++)
    {
        cin >> w[i]; // n개의 원소
    }
    
    
    int total = 0;
    for (int i=1;i<=n;i++)
    {
        total = total + w[i];
    }
    
    sum_of_subsets1(0, 0, total);
    
    cout << cnt << endl; //합이 W가 되는 부분집합의 개수를 출력한다.
    
    sum_of_subsets2(0, 0, total);
}

bool promising(int i, int weight, int total)
{
    return (weight + total >= W) && (weight == W || weight + w[i+1] <=W);
}

void sum_of_subsets1(int i, int weight, int total)
{
    if (promising(i,weight,total))
        if (weight == W)
        {
            cnt++;
        }
    else
    {
        include[i+1] = 1;
        sum_of_subsets1(i+1, weight + w[i+1], total - w[i+1]);
        include[i+1] = 0;
        sum_of_subsets1(i+1, weight, total-w[i+1]);
    }
}

void sum_of_subsets2(int i, int weight, int total)
{
    if (promising(i,weight,total))
        if (weight == W)
        {
            for (int j=1; j<=i; j++)
            {
                if (i == j)
                    cout << w[j] << endl; // 원소의 합이 W가 되는 모든 부분집합을 한 줄에 하나씩 출력한다.
                else if (include[j] == 1)
                    cout << w[j] << " ";
            }
        }
    else
    {
        include[i+1] = 1;
        sum_of_subsets2(i+1, weight + w[i+1], total - w[i+1]);
        include[i+1] = 0;
        sum_of_subsets2(i+1, weight, total-w[i+1]);
    }
}