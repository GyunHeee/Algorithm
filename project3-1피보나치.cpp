#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long Longint;

int main()
{
    int size;
    Longint a = 1;
    Longint b = 2;
    Longint c;
    int max;
    cin >> size >> max;
    if (size > 1)
    {
        while (--size)
        {
            c = (a + b) % max;
            a = b;
            b = c;
        }
        cout << c;
    }
    else
    {
        cout << size;
    }
    return 0;
}
