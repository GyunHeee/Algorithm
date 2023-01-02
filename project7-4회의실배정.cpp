#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct time1
{
    int start;
    int end;
}time1;

time1 curri[100001];
time1 answer[100001];

int cmp1(const void* a, const void* b);
int cmp2(const void* a, const void* b);

int top = 0;

int main(void)
{
    time1 tmp;
    time1 class_1;
    
    tmp.end = 99999;
    tmp.start = 99999;
    
    int size;
    int cnt = 1;
    int temp = 1;
    int j = 2;
    
    cin >> size;
    cin >> class_1.start >> class_1.end;
    
    curri[1] = class_1;
    
    for (int i = 2; i <= size; i++)
    {
        scanf("%d %d", &class_1.start, &class_1.end);
        curri[i] = class_1;
    }
    
    qsort(curri, size + 1, sizeof(time1), cmp1);
    
    for (int i = 1; i <= size; i++)
    {
        if (curri[i].end == curri[i + 1].end)
            cnt++;
        else
        {
            qsort(curri + temp, cnt, sizeof(time1), cmp2);
            temp = i + 1;
            cnt = 1;
        }
    }
    tmp = curri[1];
    answer[top++] = tmp;
    for (int i = 2; i <= size; i++)
    {
        if (tmp.end <= curri[i].start)
        {
            tmp = curri[i];
            answer[top++] = tmp;
            j++;
        }
    }
    cout << j-1;
    cout << "\n";
    
    for (int i = 0; i < top; i++)
    {
        printf("%d %d\n", answer[i].start, answer[i].end);
    }

    return 0;
}
int cmp1(const void* a, const void* b)
{
    time1 num1 = *(time1*)a;
    time1 num2 = *(time1*)b;

    if (num1.end > num2.end)
        return 1;

    if (num1.end < num2.end)
        return -1;

    return 0;
}
int cmp2(const void* a, const void* b)
{
    time1 num1 = *(time1*)a;
    time1 num2 = *(time1*)b;

    if (num1.start > num2.start)
        return 1;

    if (num1.start < num2.start)
        return -1;

    return 0;
}