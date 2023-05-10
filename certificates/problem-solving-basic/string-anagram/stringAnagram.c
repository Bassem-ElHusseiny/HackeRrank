#include <stdio.h>
#include <stdlib.h>
int compare(const char **a, const char **b)
{
  return strcmp(*a, *b);
}

int compare_chars(const char *a, const char *b)
{

  return *a - *b;
}
int binarySearchString(char **arr, int n, char target[])      //------------ log(n) ----------//
{
  int low = 0;
  int high = n - 1;
  int count = 0;
  int i = 0;
  while (low <= high)
  {

    i++;
    int mid = low + (high - low) / 2;
    int cmp = strcmp(arr[mid], target);
    if (cmp == 0)
    {
      count++;
      int left = mid - 1;
      int right = mid + 1;
      while (left >= 0 && strcmp(arr[left], target) == 0)
      {
        count++;
        left--;
      }
      while (right < n && strcmp(arr[right], target) == 0)
      {
        count++;
        right++;
      }
      break;
    }
    if (cmp < 0)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return count;
}

int* stringAnagram(int dictionary_count, char** dictionary, int query_count, char** query, int* result_count)
{
  char **new_query = (char **)calloc(query_count, sizeof(char *));

  for (int i = 0; i < query_count; i++)
  {
    int n = strlen(query[i]);
    new_query[i] = (char *)calloc(n + 1, sizeof(char));
    strcpy(new_query[i], query[i]);
    qsort(new_query[i], n, sizeof(char), compare_chars);                //------------ n log(n) ----------//
  }

  char **new_dec = (char **)calloc(dictionary_count, sizeof(char *));
  for (int i = 0; i < dictionary_count; i++)
  {
    int n = strlen(dictionary[i]);
    new_dec[i] = (char *)calloc(n + 1, sizeof(char));
    strcpy(new_dec[i], dictionary[i]);
    qsort(new_dec[i], n, sizeof(char), compare_chars);                //------------ n log(n) ----------//
  };

  qsort(new_dec, dictionary_count, sizeof(char *), compare);         //------------ n log(n) ----------//
  
  int *ans = (int *)calloc(query_count, sizeof(int));
  for (int i = 0; i < query_count; i++)
  {
    ans[i] = binarySearchString(new_dec, dictionary_count, new_query[i]);        //------------ log(n) ----------//
  }

  *result_count = query_count;

  return ans;
}