#include <iostream>
#include <vector>
#define newMatrix(n,s,i) matrix n(s, vector<int>(s , i))
using namespace std;
typedef vector<vector<int>> matrix;
typedef struct t {
    int key;
    struct t* left;
    struct t* right;
}tree_node;
int n;

void printTriangle(matrix a) {
    for (int i = 1; i < a.size(); i++)
        for (int j = i-1; j < a.size()-1; j++)
            cout << a[i][j] << (j == a.size() - 2 ? "\n" : " ");
}

void printMatrix(matrix a) {
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            cout << a[i][j] << (j == a.size() - 1 ? "\n" : " ");
}

int sum(int i, int j,vector<int> p) {
    int sum = 0;
    for (; i <= j;sum+=p[i++]);
    return sum;
}

tree_node* makeTree(int i, int j,matrix R, vector<int> key) {
    if (i > j) return NULL;
    tree_node* root = (tree_node*)malloc(sizeof(tree_node));
    root->key = key[R[i][j]];
    root->left = makeTree(i, R[i][j] - 1, R, key);
    root->right = makeTree(R[i][j]+1, j, R, key);
    return root;
}

void preorder(tree_node* cur) {
    static int i = 0;
    if (cur) {
        cout << cur->key<<(++i%n==0?"\n":" ");
        preorder(cur->left);
        preorder(cur->right);
    }
}

void inorder(tree_node* cur) {
    static int i = 0;
    if (cur) {
        inorder(cur->left);
        cout << cur->key<< (++i%n==0 ? "\n" : " ");
        inorder(cur->right);
    }
}

int main() {
    cin >> n;
    vector<int> key(n+1);
    vector<int> p(n+1);
    for (int i = 1; i <= n; cin >> key[i++]);
    for (int i = 1; i <= n; cin >> p[i++]);
    newMatrix(A, n+2, 0);
    newMatrix(R, n+2, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n- i; j++) {
            A[j][i + j] = A[j][j - 1] + A[j + 1][i + j];
            R[j][i + j] = j;
            for (int k = 1; k <= i; k++) {
                if (A[j][i + j] > A[j][j + k - 1] + A[j + k + 1][i + j]) {
                    R[j][i + j] = j + k;
                    A[j][i + j] = A[j][j + k - 1] + A[j + k + 1][i + j];
                }
            }
            A[j][i+j] +=sum(j, j + i, p);
        }
    }
    printTriangle(A);
    printTriangle(R);
    cout << A[1][n]<<endl;
    tree_node* BST = makeTree(1,n,R, key);
    preorder(BST);
    inorder(BST);
}
