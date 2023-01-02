// 중복되는 경로중 최소값이면 부호 바꾸고 맥스값을 1000000로 큰값으로 지정
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
vector<int> col;

int cnt;

vector<int> tmp;
string maxString = "";

long long maxNum = -1;

bool promising(int i);
void queens(int i);


int main(void)
{
    cin >> n; // n*n행렬
    if (n<4)
    {
        EXIT_FAILURE;
    }
    col.resize(n+1);

    queens(0);
    
    cnt = (int)tmp.size()/n;
    cout << cnt << endl; // 가능한 보드의 배치 개수를 출력
    
    
    cout << maxNum; // 경로 중 문자열로 취급했을때 최대값을 출력
    
   
    // tmp를 n만큼 쪼개고 그것의 크기를 비교해서 젤 큰것을 출력
    
}

bool promising(int i)
{
    int k= 1;
    bool flag = true;

    while (k<i && flag)
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            flag = false;
        k++;
    }
    return flag;
}

void queens(int i)
{
    int j;
    
    
    if (promising(i))
    {
        if (i== n)
        {
            for (int k=1;k<=n;k++)
            {
                maxString = maxString + to_string(col[k]);
                tmp.push_back(col[k]);
            }
            if (stoll(maxString) > maxNum) // 부호 바꾸기
            {
                maxNum = stoll(maxString);
            }
            maxString.clear();
        }
        
        else
            for (j=1;j<=n;j++)
            {
                col[i+1] = j;
                queens(i+1);
            }
    }
}
