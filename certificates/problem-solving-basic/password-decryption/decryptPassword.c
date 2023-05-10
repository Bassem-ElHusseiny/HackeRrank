char *decryptPassword(char *s)
{
  int len = strlen(s);
  int j = 0;
  int x = 0;
  char *newS = (char *)calloc(x, sizeof(char));
  for (int i = 0; i < len; i++)
  {
    if (isdigit(s[i]) && s[i] != '0')
    {
      j++;
      continue;
    }
    if ((i < len - 2) && s[i + 2] == '*')
    {
      x += 2;
      newS = (char *)realloc(newS, x * sizeof(char));
      newS[x - 2] = s[i + 1];
      newS[x - 1] = s[i];
      i += 2;
    }
    else if (s[i] == '0')
    {

      newS = (char *)realloc(newS, ++x * sizeof(char));
      newS[x - 1] = s[j - 1];
      j--;
    }
    else
    {

      newS = (char *)realloc(newS, ++x * sizeof(char));
      newS[x - 1] = s[i];
    }
  }
  
newS = (char *)realloc(newS, ++x * sizeof(char));
newS[x-1]='\0';

  return newS;
}