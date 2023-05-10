#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long compare(long *a, long *b)
{
  return *b - *a;
}

long minTime(int files_count, int* files, int numCores, int limit)
{
  long total = 0;
  int n = 0;
  long *max = (long *)calloc(n, sizeof(long));
  for (int i = 0; i < files_count; i++)
  {
    if (!(files[i] % numCores))
    {
      max = (long *)realloc(max, ++n * sizeof(long));
      max[n - 1] = files[i];
      continue;
    }
    total += files[i];
  }

  qsort(max, n, sizeof(long), compare);
 
  for (int i = 0; i < n; i++)
  {
    if (i < limit)
    {
      total += (max[i] / numCores);
    }
    else
    {
      total += max[i];
    }
  }
  free(max);
  return total;
}