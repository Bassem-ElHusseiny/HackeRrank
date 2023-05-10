char * decryptPassword(char *s)
{
  int len = strlen(s);
  char temp;
  int j = 0;
  int i = 0;
  int x = 0;
  char *numbers = (char *)calloc(x, sizeof(char));
  for (i; i < len; i++)
  {
    if (isdigit(s[i]) && s[i] != '0')
    {
      numbers = (char *)realloc(numbers, ++x * sizeof(char));
      numbers[x - 1] = s[i];
      j++;
      continue;
    }

    if (s[i] == '*')
    {

      temp = s[i - j - 1];
      s[i - j - 1] = s[i - j - 2];
      s[i - j - 2] = temp;
      j++;
    }
    else if (s[i] == '0')
    {
      s[i - j] = numbers[(x--) - 1];
    }
    else
    {
      s[i - j] = s[i];
    }
  }

  {
    s[i - j] = '\0';
  }

  free(numbers);
  return s;
}