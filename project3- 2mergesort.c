#include <stdio.h>

void mergesort2(int low, int high);
void merge2(int low, int mid, int high);

int cnt=0;
int S[100] = {0};
int cnt2 = 0;

void mergesort2(int low, int high)
{
    cnt2++;
    if (low<high)
    {
        int mid = (low + high)/2;
        mergesort2(low,mid);
        mergesort2(mid+1, high);
        merge2(low,mid,high);
        cnt++;
    }
}

void merge2(int low, int mid, int high)
{
    int i= low;
    int j = mid+1;
    int k=0;
    int U[high-low-1];
    
    while (i<=mid&& j<=high)
        U[k++] = (S[i]<S[j])? S[i++]:S[j++];
    if (i>mid)
        while (j<=high)
            U[k++] = S[j++];
    else
        while (i<=mid)
            U[k++] = S[i++];
    for (int t=low; t<=high;t++)
        S[t] = U[t-low];
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&S[i]);
    }
    mergesort2(0, n-1);
    printf("%d\n",cnt); //merge2 호출횟수 출력
    printf("%d\n",cnt2); //mergesort 호출횟수 출력
    for (int i=0;i<n;i++)
    {
        if (i==n-1)
            printf("%d",S[i]);
        else
            printf("%d ",S[i]);
    }
}
