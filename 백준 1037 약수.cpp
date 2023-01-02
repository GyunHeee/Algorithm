
 //양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다.
 //어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.
 
// 짝수, 홀수 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const short MAX = 50;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count;
    int res = 0;
    vector<int> childList;
    cin >> count; // 개수를 입력받음
    
    childList.resize(count);

    for (int i = 0; i < count; i++)
        cin >> childList[i]; // count개의 수를 입력받음

    sort(childList.begin(), childList.end()); // 수를 오름차순으로 정렬

    if (count % 2) // 홀수인 경우 중앙값을 제곱해 출력
        res = childList[count / 2] * childList[count / 2];
    else // 짝수인 경우 최대값과 최소값을 곱해 출력
        res = childList[0] * childList[count-1];

    cout << res;

    return 0;
}

//input: 2
  //     4 2
//ouput: 8

//input: 6
  //     3 4 2 12 6 8
//output: 24