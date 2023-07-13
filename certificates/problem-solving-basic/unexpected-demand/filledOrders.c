#include <stdio.h>
int compare(int *a, int *b)
{
  return *a - *b;
}

int filledOrders(int order_count, int* order, int k)
{

  qsort(order, order_count, sizeof(int), compare);
  int filled = 0;
  for (int i = 0; i < order_count; i++)
  {
    if (order[i] <= k)
    {
      filled++;
      k -= order[i];
    }
    else
    {
      break;
    }
  }
  return filled;
}
