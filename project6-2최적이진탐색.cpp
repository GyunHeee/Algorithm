#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 999999

typedef vector<vector<int>> matrix_t;

typedef struct node *node_ptr;
typedef struct node
{
    int key;
    node_ptr left;
    node_ptr right;
}node_t;

 
void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R);
int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A);
node_ptr create_node(int key);
void preorder(node_ptr node, vector<int>& v);
void inorder(node_ptr node, vector<int>& v);
node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R);

int main(void)
{
    int n;
    cin >> n;
    vector<int> key(n+1);
    vector<int> p(n+1);
    for (int i=1; i<=n;i++)
    {
        cin >> key[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    
    matrix_t A, R;

    A.resize(n+2,vector<int>(n+2,0));
    R.resize(n+2,vector<int>(n+2,0));
    optsearchtree(n, p, A, R);
    
    node_ptr root = tree(1, n, key, R);
    vector<int> in, pre;
    preorder(root, pre);
    inorder(root, in);
   
    
    for (int i = 1; i <= n + 1;i++) {
            for (int j = i-1; j < n + 1; j++) {
                if (j == n) cout << A[i][j] << endl;
                else cout << A[i][j] << " ";
            }
    }
    
    
    for (int i = 1; i <= n + 1;i++) {
            for (int j = i-1; j < n + 1; j++) {
                if (j == n) cout << R[i][j] << endl;
                else cout << R[i][j] << " ";
            }
    }
    cout << A[1][n] << endl;
    for (int i = 0; i < pre.size(); i++)
        if (i== pre.size() -1)
            cout << pre[i];
        else
            cout << pre[i] << " ";
    cout << "\n";
    for (int i = 0; i < in.size(); i++)
        if (i == in.size()-1)
            cout << in[i];
        else
            cout << in[i] <<" ";
    cout << "\n";
    
}

node_ptr create_node(int key)
{
    node_ptr node = (node_ptr)malloc(sizeof(node_t));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R)
{
    int k = R[i][j];
    if (k == 0)
        return NULL;
    else
    {
        node_ptr node = create_node(keys[k]);
        node->left = tree(i, k - 1, keys, R);
        node->right = tree(k + 1, j, keys, R);
        return node;
    }
}

int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A)
{
    int minValue = INF, value, psum;
    for (int k = i; k <= j; k++) {
        psum = 0;
        for (int m = i; m <= j; m++)
            psum += p[m];
        value = A[i][k - 1] + A[k + 1][j] + psum;
        if (minValue > value) {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R)
{
    int i, j, k, diagonal;
    for (i = 1; i <= n; i++) {
        A[i][i - 1] = 0; A[i][i] = p[i];
        R[i][i - 1] = 0; R[i][i] = i;
    }
    A[n + 1][n] = R[n + 1][n] = 0;

    for (diagonal = 1; diagonal <= n - 1; diagonal++)
        for (i = 1; i <= n - diagonal; i++) {
            j = i + diagonal;
            A[i][j] = minimum(i, j, k, p, A);
            R[i][j] = k;
        }
}

void preorder(node_ptr node, vector<int>& v)
{
    if (node != NULL)
    {
        v.push_back(node->key);
        preorder(node->left, v);
        preorder(node->right, v);
    }
}

void inorder(node_ptr node, vector<int>& v)
{
    if (node != NULL)
    {
        inorder(node->left, v);
        v.push_back(node->key);
        inorder(node->right, v);
    }
}