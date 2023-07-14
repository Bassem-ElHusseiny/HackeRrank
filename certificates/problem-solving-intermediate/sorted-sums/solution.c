#include <stdlib.h>

void update(int x, int val, long *arr)  //------- Fenwick Tree ------//
{

    while (x <= 1e6)
    {
        arr[x] += val;
        x += x & (-x);
    }
}

long prefixSum(int x, long *arr)   //------- Fenwick Tree ------//
{
    long sum = 0;
    while (x > 0)
    {
        sum += arr[x];
        x -= x & (-x);
    }
    return sum;
}

int sortedSum(int a_count, int *a)
{
    int modulo = 1e9 + 7;
    int maxNumber = 1e6;
    long *index = (long *)calloc(maxNumber + 1, sizeof(long));     // index[1e6+1]={0}
    long *preSum = (long *)calloc(maxNumber + 1, sizeof(long));   // preSum[1e6+1]={0}
    long sum = 0, order = 0, diff = 0;
    long acc = 0, ans = 0;

    for (int i = 0; i < a_count; i++)
    {
        order = prefixSum(a[i], index) + 1;
        diff = sum - prefixSum(a[i], preSum);
        acc = acc + order * a[i] + diff;
        ans += acc % modulo;
        sum += a[i];
        update(a[i], 1, index);
        update(a[i], a[i], preSum);
    }
    free(index);
    free(preSum);
    return ans % modulo;
}