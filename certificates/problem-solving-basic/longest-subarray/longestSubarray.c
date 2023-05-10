#include <stdio.h>
#include <stdlib.h>

int longestSubarray(int arr_count, int* arr)
{
  int x, y, max;
  x = y = max = 1;

  for (int i = 1; i < arr_count; i++)
  {
    if (arr[i - 1] == arr[i])
    {
      x++;
      y++;
    }
    else if (arr[i - 1] == (arr[i] - 1))
    {
      x = y + 1;
      y = 1;
    }
    else if (arr[i - 1] == (arr[i] + 1))
    {
      y = x + 1;
      x = 1;
    }
    else
    {
      x = y = 1;
    };

    max = (x > max) ? ((x > y) ? x : y) : ((max > y) ? max : y);
  }

  return max;
}