#include <stdio.h>
#include <stdlib.h>

// --------------------------------------  O(n log n)  Using Quick sort  ---------------------------------------------------//

long gcd(long a, long b) // Greatest Common Divisor Function
{
  return b > 0 ? gcd(b, a % b) : a;
}

long compare(const long *a, const long *b) // Compare Function To Sort 2D Array
{
  return (*a - *b) ? (*a - *b) : (*(a + 1) - *(b + 1));
};
long nearlySimilarRectangles(int sides_rows, int sides_columns, long **sides)
{
  long arr[sides_rows][2];

  for (int i = 0; i < sides_rows; i++)
  {
    long z = gcd(sides[i][0], sides[i][1]);
    arr[i][0] = sides[i][0] / z;
    arr[i][1] = sides[i][1] / z;
  }

  qsort(arr, sides_rows, sizeof(arr[0]), compare);

  long count = 1;
  long sum = 0;
  long acc = 0;

  for (int i = 0; i < sides_rows - 1; i++)
  {
    if (arr[i][0] == arr[i + 1][0] && arr[i][1] == arr[i + 1][1])
    {
      count++;
      acc = ((count * (count - 1)) / 2);           // n(n-1)/2
      continue;
    }
    sum += acc;
    count = 1;
    acc = 0;
  }
  sum += acc;

  return sum;
};
