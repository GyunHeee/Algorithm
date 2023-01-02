// inorder, preorder보고 허프만트리 그리기 가능! 자식노드 두개의 합이 부모노드임
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <string>
using namespace std;

typedef struct node* node_ptr;
typedef struct node
{
    char symbol;
    int frequency;
    node_ptr left;
    node_ptr right;
} node_t;

struct compare
{
    bool operator()(node_ptr p, node_ptr q)
    {
        return p->frequency > q->frequency;
    }
};

typedef priority_queue<node_ptr, vector<node_ptr>, compare> PrioiritQueue;
void huffman(int n, PrioiritQueue& PQ);
node_ptr create_node(char symbol, int fre);
void preorder(node_ptr root);
void inorder(node_ptr root);
void encode(node_ptr root, vector<int>& code, map<char, vector<int>>& encoder);
void decode(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder);

int main(void)
{
    int n; // 문자의 개수
    cin >> n;
    vector<char> symbor(n + 1);
    vector<int> frequency(n + 1);
    PrioiritQueue PQ;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> symbor[i]; //n개의 문자
    }
    for (int i = 1; i < n + 1; i++)
    {
        cin >> frequency[i]; //빈도값
    }
    // 빈도값은 내림차순으로 정렬되어있어야함
    for (int i = 1; i < n + 1; i++)
        PQ.push(create_node(symbor[i], frequency[i]));
    huffman(n, PQ);
    node_ptr root = PQ.top();
    preorder(root); // 허프만 트리의 preorder traversal 결과를 쓴다.
    cout << endl;
    inorder(root); //  허프만 트리의 inorder traversal 결과
    cout << endl;
    
    int m;
    cin >> m; //문자열의 개수
    vector<int> code1;
    vector<int> code2;
    map<char, vector<int>> encoder;
    encode(PQ.top(), code1, encoder);
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str; // 한 줄에 하나씩 텍스트 문자열이 주어짐
        int j = 0;
        vector<int> a;
        while (j < str.length())
        {
            a = encoder.at(str[j]);
            for (int number : a)
                cout << number;  // T1개의 문자열을 인코딩한 허프만 코드를 한 줄에 하나씩 출력
            j++;
        }
        cout << endl;
    }
    
    map<char, vector<int>> decoder;
    cin >> m; ///문자열의 개수
    decode(PQ.top(), code2, decoder);
    for (int i = 1; i <= m; i++)
    {
        string str;
        cin >> str; // 한 줄에 하나씩 허프만 코드 문자열이 주어짐
        node_ptr no = PQ.top();
        int j = 0;
        while (j < str.length())
        {
            if (str[j] == '0')
            {
                no = no->left;
                j++;
            }
            else if (str[j] == '1')
            {
                no = no->right;
                j++;
            }
            if (no->symbol != '+')
            {
                cout << no->symbol; // T2개의 허프만 코드를 디코딩한 텍스트 문자열을 한 줄에 하나씩 출력
                no = PQ.top();
            }
        }
        cout << endl;
    }

    return 0;
}
void huffman(int n, PrioiritQueue& PQ)
{
    for (int i = 1; i < n; i++)
    {
        node_ptr p = PQ.top();
        PQ.pop();
        node_ptr q = PQ.top();
        PQ.pop();
        node_ptr r = create_node('+', p->frequency + q->frequency);
        r->left = p;
        r->right = q;
        PQ.push(r);
    }
}
node_ptr create_node(char sym, int fre)
{
    node_ptr a = (node_ptr)malloc(sizeof(node_t));
    a->left = NULL;
    a->right = NULL;
    a->symbol = sym;
    a->frequency = fre;

    return a;
}
void preorder(node_ptr root)
{
    if (root != NULL)
    {
        cout << root->symbol << ':' << root->frequency << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node_ptr root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->symbol << ':' << root->frequency << " ";
        inorder(root->right);
    }
}
void decode(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder)
{
    if (root->symbol != '+')
    {
        vector<int> ret;
        ret.resize(code.size());
        copy(code.begin(), code.end(), ret.begin());
        decoder.insert(make_pair(root->symbol, ret));
    }
    else if (root != NULL)
    {
        code.push_back(0);
        decode(root->left, code, decoder);
        code.pop_back();
        code.push_back(1);
        decode(root->right, code, decoder);
        code.pop_back();
    }
}
void encode(node_ptr root, vector<int>& code, map<char, vector<int>>& encoder)
{
    if (root->symbol != '+')
    {
        vector<int> ret;
        ret.resize(code.size());
        copy(code.begin(), code.end(), ret.begin());
        encoder.insert(make_pair(root->symbol, ret));
    }
    else if (root != NULL)
    {
        code.push_back(0);
        encode(root->left, code, encoder);
        code.pop_back();
        code.push_back(1);
        encode(root->right, code, encoder);
        code.pop_back();
    }
}
