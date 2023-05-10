#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const char **a, const char **b)
{
  return strcmp(*a, *b);
}

char** mostActive(int customers_count, char** customers, int* result_count)
{
  qsort(customers, customers_count, sizeof(char *), compare);

  int size = 0;
  char **arr = (char **)malloc(size * sizeof(char *));
  
  int count = 1;
  for (int i = 0; i < customers_count - 1; i++)
  {
    if (strcmp(customers[i], customers[i + 1]) == 0)
    {
      count++;
      continue;
    }

    if (count >= customers_count * 0.05)
    {
      arr = (char **)realloc(arr, ++size * sizeof(char *));
      arr[size - 1] = customers[i];
    }
    count = 1;
  }

  if (count >= customers_count * 0.05)
  {
    arr = (char **)realloc(arr, ++size * sizeof(char *));
    arr[size - 1] = customers[customers_count - 1];
  }

  *result_count = size;
  return arr;
}
