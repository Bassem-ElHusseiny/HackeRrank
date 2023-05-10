#include <stdio.h>
#include <string.h>

int compare_chars(const char *a, const char *b)
{

  return *a - *b;
}

char** possibleChanges(int usernames_count, char** usernames, int* result_count) 
{

  char **result = (char *)malloc(usernames_count * sizeof(char *));

  for (int i = 0; i < usernames_count; i++)
  {
    char *temp = (char *)calloc(strlen(usernames[i]) + 1, sizeof(char));
    strcpy(temp, usernames[i]);
    qsort(temp, strlen(temp), sizeof(char), compare_chars);
    if (strcmp(usernames[i], temp))
    {
      result[i] = "YES";
    }
    else
    {
      result[i] = "NO";
    }
    free(temp);
  }

  *result_count=usernames_count;
  return result;
}