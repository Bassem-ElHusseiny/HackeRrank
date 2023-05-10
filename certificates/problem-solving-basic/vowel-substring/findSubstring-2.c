#include <stdio.h>
#include <string.h>

char* findSubstring(char* s, int k)
{
  char *result = (char *)malloc((k + 1) * sizeof(char));
  int key[256] = {};
  char vowels[] = "aeiou";
  for (int i = 0; i < strlen(vowels); i++)
  {
    key[vowels[i]] = 1;
  }

  int count = 0;
  int ans = 0;

  for (int i = 0; i < k; i++)
  {
    count += key[s[i]];
  }
  int max = count;
  for (int i = k; i < strlen(s); i++)
  {
    count += key[s[i]];
    count -= key[s[i - k]];

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