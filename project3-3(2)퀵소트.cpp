#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int S[100];
int count1=0;

void quicksort(int low,int high);
void partition(int low,int high,int &pivotpoint);

void quicksort(int low,int high)
{
    int pivotpoint;
    
    if (low<high)
    {
        count1++;
        partition(low,high,pivotpoint);
        quicksort(low,pivotpoint-1);
        quicksort(pivotpoint+1,high);
    }
}

void partition(int low,int high,int &pivotpoint)
{
    int pivotitem = S[low];
    
    int j=low;
    for (int i=low+1;i<=high;i++)
        if (S[i]<pivotitem)
        {
            j++;
            swap(S[i],S[j]);
        }
    pivotpoint = S[j];
    swap(S[low],S[pivotpoint]);
}

int main(void)
{
    int n;
    cin>>n;
    
    for (int i=0;i<n;i++)
    {
        cin>>S[i];
    }
    
    partition(0,n-1,S[0]);
    for (int i=0;i<n;i++)
    {
        cout<< S[i]<<" ";
    }
    printf("\n");
    
    
    
    quicksort(0, n-1);
    printf("%d\n",count1);
    
    for (int i=0;i<n;i++)
    {
        cout<<S[i]<<" ";
    }
    
}
