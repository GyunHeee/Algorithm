#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int S[100];
int count1 = 0;
int N;
int cnt=0;
void quicksort(int low, int high);
void partition(int low, int high, int& pivotpoint);

void quicksort(int low, int high)
{
    int pivotpoint;

    if (low < high)
    {
        count1++;
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}

void partition(int low, int high, int& pivotpoint)
{
    swap(S[low],S[high]);
    int pivotitem = S[low];

    int j = low;
    for (int i = low + 1; i <= high; i++)
        if (S[i] < pivotitem)
        {
            j++;
            swap(S[i], S[j]); cnt++;
        }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]); cnt++;
    if (low == 0 && high == N - 1)
          {
             for (int i = 0; i < N; i++)
             {
                if (i == N - 1)
                   cout << S[i];
                else
                   cout << S[i] << " ";
             }
             cout << endl;
          }
}

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    //partition(0, n - 1, S[0]);



    quicksort(0, N - 1);
    printf("%d\n", count1);

    for (int i = 0; i < N; i++)
    {
        cout << S[i] << " ";
    }
    
    cout << "\n";
    cout << cnt;

}