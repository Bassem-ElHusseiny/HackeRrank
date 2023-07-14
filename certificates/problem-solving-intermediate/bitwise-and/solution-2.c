int compare(const int *a, const int *b)
{
    return *a - *b;
}

long countPairs(int arr_count, int *arr)
{
    qsort(arr, arr_count, sizeof(int), compare);
    int size = 1;
    int *re_num = (int *)calloc(size, sizeof(int));
    int *new_arr = (int *)calloc(size, sizeof(int));
    re_num[0] = 1;
    new_arr[0] = arr[0];

    for (int i = 0; i < arr_count - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            ++re_num[size - 1];
            continue;
        }
        new_arr = (int *)realloc(new_arr, ++size * sizeof(int));
        new_arr[size - 1] = arr[i + 1];
        re_num = (int *)realloc(re_num, size * sizeof(int));
        re_num[size - 1] = 1;
    }

    int andOp = 0;
    long res = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            andOp = new_arr[i] & new_arr[j];
            if (andOp && (!(andOp & (andOp - 1))))
            {
                if (new_arr[i] == new_arr[j])
                {
                    res += ((long)re_num[i] * (re_num[i] - 1)) / 2;    // n(n-1)/2
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