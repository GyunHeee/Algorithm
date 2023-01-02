#include <iostream>
#include <vector>
#include <string>
#define newMatrix(n,s,i) matrix n(s, vector<int>(s , i))
using namespace std;
typedef vector<vector<int> > matrix;

void printTriangle(matrix a) {
    for (int i = 1; i < a.size(); i++)
        for (int j = i; j < a.size(); j++)
            cout << a[i][j] << (j == a.size() - 1 ? "\n" : " ");
}

string order(int i, int j, matrix P) {
    return i==j? "(A" + to_string(i)+")": "(" + order(i, P[i][j], P)+order(P[i][j] + 1, j, P) + ")";
}

string prefix(int i, int j, matrix P) {
    return i==j? "A" + to_string(i): "*"+prefix(i, P[i][j], P)+prefix(P[i][j] + 1, j, P);
}

string postfix(int i, int j, matrix P) {
    return i==j? "A" + to_string(i): postfix(i, P[i][j], P)+postfix(P[i][j] + 1, j, P) + "*";
}

int main() {
    int size;
    cin >> size;
    vector<int> d(size+1);
    newMatrix(M, size + 1,1000000);
    newMatrix(P, size + 1,0);
    for (int i =0; i <= size;M[i][i] = 0, i++)
        cin >> d[i];
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size-i; j++)
            for (int k = 0; k < i; P[j][i + j] = M[j][i + j] <= M[j][j + k] + M[j + k + 1][i + j] + d[j - 1] * d[j + k] * d[i + j] ? P[j][i + j] : j + k, M[j][i + j] = M[j][i + j] <= M[j][j + k] + M[j + k + 1][i + j] + d[j - 1] * d[j + k] * d[i + j] ? M[j][i + j] : M[j][j + k] + M[j + k + 1][i + j] + d[j - 1] * d[j + k] * d[i + j], k++);
    printTriangle(M);
    printTriangle(P);
    cout << M[1][size] << endl;
    cout << order(1, size, P) <<endl;
    cout << postfix(1, size, P) <<endl;
    cout << prefix(1, size, P) <<endl;
    return 0;
}