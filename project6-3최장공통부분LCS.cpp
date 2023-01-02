#include <iostream>
#include <vector>
#include <string>

#define matrix_t vector<vector<int>>

using namespace std;

void LCS(string X, string Y, matrix_t& D, matrix_t& P);
string get_lcs(int i, int j, matrix_t P, string x);

int main() {
   string X, Y;
   cin >> X >> Y;
   
   X = " " + X;
   Y = " " + Y;

   matrix_t DP(X.length(), vector<int>(Y.length(), 0));
   matrix_t P(X.length(), vector<int>(Y.length(), 0));
   
   LCS(X, Y, DP, P);

   cout << DP[X.length() - 1][Y.length() - 1] << endl;
   cout << get_lcs(X.length()-1, Y.length()-1, P, X);
}

void LCS(string X, string Y, matrix_t& D, matrix_t& P) {
   
   for (int i = 1; i < X.length(); i++) {
      for (int j = 1; j < Y.length(); j++) {
         if (X[i] == Y[j]) {
            D[i][j] = D[i - 1][j - 1] + 1;
            P[i][j] = 1;
         }
         else {
            D[i][j] = max(D[i][j - 1] , D[i - 1][j]);
            P[i][j] = D[i][j - 1] > D[i - 1][j] ? 2 : 3;
         }
      }
   }
}
string get_lcs(int i, int j, matrix_t P, string x) {
   if (i == 0 || j == 0) return "";
   else {
      if (P[i][j] == 1) return get_lcs(i - 1, j - 1, P, x) + x[i];
      else if (P[i][j] == 2) return get_lcs(i, j-1, P, x);
      else return get_lcs(i-1, j, P, x);
   }
}
