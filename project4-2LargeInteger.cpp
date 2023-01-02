#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int threshold=1;
int cnt =0;

using namespace std;

typedef vector<int> LargeInteger;

void remove_leading_zeros(LargeInteger&v);
void roundup_carry(LargeInteger &v);
void ladd(LargeInteger a, LargeInteger b, LargeInteger &c);
void rem_by_ex(LargeInteger u,int v, LargeInteger &d);
void pow_by_ex(LargeInteger u, int m, LargeInteger &v);
void lmult(LargeInteger a, LargeInteger b, LargeInteger &c);
void prod(LargeInteger u, LargeInteger v, LargeInteger &r);
void div_by_ex(LargeInteger u, int v, LargeInteger &d);

int main(void)
{
    cin >> threshold;

    string str1, str2;
    vector<int> u, v, res;

    cin >> str1;
    for (int i = str1.size() - 1; i >= 0; i--)
        u.push_back(str1[i] - '0');
    cin >> str2;
    for (int i = str2.size() - 1; i >= 0; i--)
        v.push_back(str2[i] - '0');

    prod(u, v, res);
    
    cout << cnt << endl;
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    
}

void prod(LargeInteger u, LargeInteger v, LargeInteger &r)
{
    cnt++;
    LargeInteger x,y,w,z;
    LargeInteger t1, t2, t3, t4, t5, t6, t7, t8;
    
    int n= max(u.size(), v.size());
    
    if (u.size() == 0 || v.size() ==0)
    {
        r.resize(0);
    }

    else if (n<=threshold)
    {
        lmult(u,v,r);
    }
    else
    {
        int m = n/2;
        div_by_ex(u,m,x); rem_by_ex(u,m,y);
        div_by_ex(v,m,w); rem_by_ex(v,m,z);
        
        //t2 <- prod(x,w) * 10^(2*m);
        prod(x,w,t1); pow_by_ex(t1,2*m,t2);
        
        //t6 <- (prod(x,z) + prod(w,y)) * 10^m;
        prod(x,z,t3); prod(w,y,t4); ladd(t3,t4,t5); pow_by_ex(t5,m,t6);
        
        prod(y,z,t7); ladd(t2,t6,t8); ladd(t8,t7,r);
    }
}

void roundup_carry(LargeInteger &v)
{
    int carry = 0;
    for (int i=0;i<v.size() ; i++)
    {
        v[i] += carry;
        carry = v[i] / 10;
        v[i] = v[i] % 10;
    }
    if (carry != 0)
    {
        v.push_back(carry);
    }
}

void ladd(LargeInteger a, LargeInteger b, LargeInteger &c)
{
    c.resize(max(a.size(),b.size()));
    fill(c.begin(),c.end(),0);
    for (int i=0;i<c.size();i++)
    {
        if (i<a.size()) c[i] += a[i];
        if (i<b.size()) c[i] += b[i];
    }
    roundup_carry(c);
}

void div_by_ex(LargeInteger u, int v, LargeInteger &d)
{
    if (u.size() == 0)
    {
        d.resize(0);
    }
    else
    {
        int k = v < u.size() ? v: u.size();
        d.resize(u.size()-k);
        copy(u.begin()+k,u.end(),d.begin());
        remove_leading_zeros(d);
    }
}

void rem_by_ex(LargeInteger u, int v, LargeInteger &d)
{
    if (u.size() == 0)
    {
        d.resize(0);
    }
    else
    {
        int k = v < u.size() ? v: u.size();
        d.resize(k);
        copy(u.begin(),u.begin()+k,d.begin());
        remove_leading_zeros(d);
    }
}



void pow_by_ex(LargeInteger u, int m, LargeInteger &v)
{
    if (u.size() == 0)
        v.resize(0);
    else
    {
        v.resize(u.size()+m);
        fill(v.begin(),v.end(),0);
        copy(u.begin(),u.end(),v.begin()+m);
    }
}

void lmult(LargeInteger a, LargeInteger b, LargeInteger &c)
{
    c.resize(a.size()+b.size()-1);
    fill(c.begin(),c.end(),0);
    for (int i=0;i<a.size();i++)
        for (int j=0;j<b.size();j++)
            c[i+j] += a[i]*b[j];
    roundup_carry(c);
}

void remove_leading_zeros(LargeInteger&v) {
    while(v.size()!=0 &&v.back()==0)
        v.pop_back();
}