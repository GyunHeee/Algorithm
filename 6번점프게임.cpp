 #include <iostream>
 #include <vector>
 #define newMatrix(n,s) matrix n(s, vector<int>(s,0))
 using namespace std;
 typedef vector<vector<int> > matrix;

 void printMatrix(matrix a) {
     for (int i = 0; i < a.size(); i++)
         for (int j = 0; j < a[i].size(); j++)
             cout << a[i][j] << (j == a[i].size() - 1 ? "\n" : " ");
 }

 bool findPath(matrix map,matrix& result,int row,int col) {
     if (row >= map.size() || col >= map.size()) return false;
     if (row == map.size() - 1 && col == map.size() - 1) return true;
     result[row][col] = findPath(map, result, row + map[row][col], col) || findPath(map, result, row, col + map[row][col]);
     return result[row][col];
 }

 int main() {
     int n;
     cin >> n;
     newMatrix(map, n);
     newMatrix(result, n);
     for (int i = 0; i < n; i++)
         for (int j = 0; j < n; cin >> map[i][j], j++);
     cout << (findPath(map,result,0,0) ? "YES" : "NO")<<endl;
     printMatrix(result);
 } 


