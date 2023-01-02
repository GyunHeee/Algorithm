#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> sequence_of_integer;

bool is_feasible(sequence_of_integer &k, sequence_of_integer &deadline);
void schedule(int n, sequence_of_integer & deadline, sequence_of_integer &J);

int main(void)
{
    int n;  // job의 개수 n
    cin >> n;
    
    sequence_of_integer deadline;
    deadline.resize(n+1);
    
    for (int i=1;i<=n;i++)
    {
        cin >> deadline[i]; // n개의 deadline이 주어짐
    }
    
    sequence_of_integer profit;
    profit.resize(n+1);
    
    for (int i=1;i<=n;i++)
    {
        cin >> profit[i]; // n개의 profit이 주어짐
    }
    // profit은 내림차순으로 정렬되어 있어야함
    
    sequence_of_integer J;
    
    schedule(n, deadline, J);
    
    int max = 0;
    for (int i=1;i<J.size();i++)
    {
        max = profit[J[i]] + max;
    }
    
    cout << max << endl; // 최대 이익의 값을 출력
    
    for (int i=1;i<J.size();i++)
    {
        if (i == J.size()-1)
            cout << profit[J[i]];  //job sequence의 순서대로 각 job의 profit을 출력한다.
        else
            cout << profit[J[i]] << " ";
    }
    
    
}

bool is_feasible(sequence_of_integer &k, sequence_of_integer &deadline)
{
    for (int i=1;i<k.size();i++)
        if (i>deadline[k[i]])
            return false;
    return true;
}

void schedule(int n, sequence_of_integer & deadline, sequence_of_integer &J)
{
    sequence_of_integer K;
    J.clear();
    J.push_back(0);
    J.push_back(1);
    for (int i=2;i<=n;i++)
    {
        K.resize(J.size());
        copy(J.begin(),J.end(),K.begin());
        int j=1;
        while (j<K.size() && deadline[K[j]] <= deadline[i])
        {
            j++;
        }
        K.insert(K.begin()+j, i);
        if (is_feasible(K, deadline))
        {
            J.resize(K.size());
            copy(K.begin(),K.end(),J.begin());
        }
    }
}
