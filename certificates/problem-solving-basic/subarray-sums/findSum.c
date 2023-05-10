#include <stdio.h>
long* findSum(int numbers_count, int* numbers, int queries_rows, int queries_columns, int** queries, int* result_count)
{

  long *result = (long *)malloc(queries_rows * sizeof(long));
  long a[numbers_count + 1];
  long b[numbers_count + 1];
  a[0] = 0;
  b[0] = 0;

  for (int i = 0; i < numbers_count; i++)
  {
    a[i + 1] = a[i] + numbers[i];
    b[i + 1] = b[i] + (numbers[i] == 0);
  }

  for (int i = 0; i < queries_rows; i++)
  {
    int x = queries[i][2];
    int r = queries[i][1];
    int l = queries[i][0];

    result[i] = a[r] - a[l - 1] + x * (b[r] - b[l - 1]);
  }
  
  *result_count=queries_rows;
  return result;
}