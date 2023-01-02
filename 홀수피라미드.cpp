#include<iostream>
typedef unsigned long long ull;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case, T;
    ull n, first, last;
    cin>>T;
    for(int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        first = 2*n*n - 4*n + 3;
        last = 2*n*n -1;
        cout << "#"<< test_case << " "<< first << " " << last <<endl;

    }
    return 0;
}
// 해당층의 처음과 끝을 출력
