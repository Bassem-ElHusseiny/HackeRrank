#include <stdio.h>
#include <string.h>

char* findSubstring(char* s, int k)
{
  char *result = (char *)malloc((k + 1) * sizeof(char));
  char vowels[] = "aeiou";
  int count = 0;
  int ans = 0;
  char *ptr;

  for (int i = 0; i < k; i++)
  {
    ptr = strchr(vowels, s[i]);
    count += (ptr != NULL);
  }
  int max = count;
  for (int i = k; i < strlen(s); i++)
  {
    ptr = strchr(vowels, s[i]);
    count += (ptr != NULL);
    ptr = strchr(vowels, s[i - k]);
    count -= (ptr != NULL);

    if (count > max)
    {
      max = count;
      ans = i - k + 1;
    }
  }

  if (max > 0)
  {
    strncpy(result, s + ans, k);
    result[k] = '\0';
    return result;
  }

  free(result);
  return "Not found!";
}
