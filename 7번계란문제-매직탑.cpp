#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int result(int top) {
    return (sqrt(8*top+1)-1)/2+1;
}

int result2(int top){
    int i = 1;
    for (; top > (i + 1) * i / 2; i++);
    return i;
}

int main() {
    int top;
    cin >> top;
    cout << result(top) << endl;
}
