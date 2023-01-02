//  백준 1929 소수 구하기(에라토스테네스의 체).cpp
//st이상 ed이하의 소수를 모두 출력하는 프로그램 작성
#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

bool s[1000001] = { 0, };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    s[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (!s[i]) {
            for (int j = i + i; j <= 1000000; j += i) {
                s[j] = 1;
            }
        }
    }
    int ans = 0;
    int st, ed, _min=-1; //st이상 ed이하의 소수를 모두 출력하는 프로그램 작성
    cin >> st >> ed;
    for (int i = st; i <= ed; i++) {
        if (!s[i]) {
            cout << i << "\n";
        }
    }
}