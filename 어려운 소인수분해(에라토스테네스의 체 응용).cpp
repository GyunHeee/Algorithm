// 첫째 줄에는 자연수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.
//둘째 줄에는 자연수 ki (2 ≤ ki ≤ 5,000,000, 1 ≤ i ≤ N)가 N개 주어진다.
//N줄에 걸쳐서 자연수 ki의 소인수들을 오름차순으로 출력하라.
//input
//5
//5 4 45 64 54

//output
//5
//2 2
//3 3 5
//2 2 2 2 2 2
//2 3 3 3

#include <iostream>

using namespace std;

const int MAX = 5000000;
const int PRIME_MAX = 190000;

bool primeCheck[MAX + 1];
int primeList[PRIME_MAX];
int primeCount;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i < (MAX / 2) + 1; i++)
    {
        if (!primeCheck[i])
        {
            primeList[primeCount++] = i;
            for (int j = 2; (j * i) < MAX; j++)
                primeCheck[j * i] = true;
        }
    }

    int tcc;

    cin >> tcc;

    while (tcc--)
    {
        int value = 1000;

        while (value > 1)
        {
            // Not Prime
            if (primeCheck[value])
            {
                for (int i = 0; i < primeCount; i++)
                {
                    if (value % primeList[i] == 0)
                    {
                        cout << primeList[i] << ' ';
                        value /= primeList[i];
                        
                        break;
                    }
                }
            }
            // Prime
            else
            {
                cout << value;
                value = 1;
            }
            value--;
        }

        cout << '\n';
    }
}