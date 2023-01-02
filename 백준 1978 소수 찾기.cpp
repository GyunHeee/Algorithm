
#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n)
{
    bool flag = true;
    int i = 2;
    while (flag && i <= (int)sqrt(n))
        if (n % i == 0)
            flag = false;
        else
            i++;
    return flag;
}
 
 //빠른 계산을 위해 에라토스테네스의 접근 방법을 사용
 //에라토스테네스의 소수 필요충분조건은 2보다 크면서 자기 자신의 제곱근까지의 수에 나눠지지 않는 수이다.

int main()
{
    int n;
    cin >> n;
    if (prime(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}


