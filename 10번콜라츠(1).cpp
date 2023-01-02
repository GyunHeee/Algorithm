#include <iostream>
#include <algorithm>
#include <vector>

#define INF 0xffff

void colartz(int k);
using namespace std;
int cnt;
int main()
{
    int min = -1,sol=0;
    for (int i = 90000; i <= 99999; i++)
    {
        colartz(i);
        if (cnt >= min)
        {
            min = cnt;
            sol = i;
        }

        cnt = 0;
    }
    cout << sol << ":" << min << endl;
    return 0;
}
void colartz(int k)
{
    cnt++;
    if (k == 1)
        return;
    if (k % 2 == 0)
    {
        k = k / 2;
        colartz(k);
    }
    else
    {
        k = k * 3 + 1;
        colartz(k);
    }
}