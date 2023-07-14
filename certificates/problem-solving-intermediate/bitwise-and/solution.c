#define maxSize 4096      // 2 ^ 12

long countPairs(int arr_count, int *arr)
{
    int re_num[maxSize] = {0};

    for (int i = 0; i < arr_count; i++)
    {
        re_num[arr[i]] += 1;
    }

    int andOp = 0;
    long res = 0;

    for (int i = 0; i < maxSize; i++)
    {
        for (int j = i; j < maxSize; j++)
        {
            andOp = i & j;
            if (andOp && (!(andOp & (andOp - 1))))
            {
                if (i == j)
                {
                    res += ((long)re_num[i] * (re_num[i] - 1)) / 2;      // n(n-1)/2
                }
                else
                {
                    res += (long)re_num[i] * re_num[j];
                }
            }
        }
    }
    return res;
}