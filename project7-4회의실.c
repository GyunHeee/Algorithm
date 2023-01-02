#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct class_time
{
    int start_time;
    int end_time;
}class_time;
class_time curri[100001];
class_time answer[100001];
int compare(const void* a, const void* b);
int compare_1(const void* a, const void* b);
int top;
int main()
{
    class_time tmp, class_1;
    tmp.end_time = 2147483648;
    tmp.start_time = 2147483648;
    int size, j = 2, cnt = 1, temp = 1;
    scanf("%d", &size);
    scanf("%d %d", &class_1.start_time, &class_1.end_time);
    curri[1] = class_1;
    for (int i = 2; i <= size; i++)
    {
        scanf("%d %d", &class_1.start_time, &class_1.end_time);
        curri[i] = class_1;
    }
    qsort(curri, size + 1, sizeof(class_time), compare);
    for (int i = 1; i <= size; i++)
    {
        if (curri[i].end_time == curri[i + 1].end_time)
            cnt++;
        else
        {
            qsort(curri + temp, cnt, sizeof(class_time), compare_1);
            temp = i + 1;
            cnt = 1;
        }
    }
    tmp = curri[1];
    answer[top++] = tmp;
    for (int i = 2; i <= size; i++)
    {
        if (tmp.end_time <= curri[i].start_time)
        {
            tmp = curri[i];
            answer[top++] = tmp;
            j++;
        }
    }
    printf("%d\n", j - 1);
    for (int i = 0; i < top; i++)
    {
        printf("%d %d\n", answer[i].start_time, answer[i].end_time);
    }

    return 0;
}
int compare(const void* a, const void* b)
{
    class_time num1 = *(class_time*)a;
    class_time num2 = *(class_time*)b;

    if (num1.end_time > num2.end_time)
        return 1;

    if (num1.end_time < num2.end_time)
        return -1;

    return 0;
}
int compare_1(const void* a, const void* b)
{
    class_time num1 = *(class_time*)a;
    class_time num2 = *(class_time*)b;

    if (num1.start_time > num2.start_time)
        return 1;

    if (num1.start_time < num2.start_time)
        return -1;

    return 0;
}
