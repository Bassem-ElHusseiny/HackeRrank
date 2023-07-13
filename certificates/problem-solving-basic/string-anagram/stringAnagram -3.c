#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const char **a, const char **b)
{
    return strcmp(*a, *b);
}

int compare_chars(const char *a, const char *b)
{
    return *a - *b;
}

int compare_search(const char *a, const char **b)
{
    return strcmp(a, *b);
}

int *stringAnagram(int dictionary_count, char **dictionary, int query_count, char **query, int *result_count)
{

    for (int i = 0; i < query_count; i++)
    {
        int n = strlen(query[i]);                                 //
        char *new_query = (char *)calloc(n + 1, sizeof(char));   // char* new_query = strdup(query[i]);
        strcpy(new_query, query[i]);                            //
        qsort(new_query, n, sizeof(char), compare_chars);      // qsort(new_query,strlen(query[i]), sizeof(char), compare_chars);
        query[i] = new_query;
    }

    for (int i = 0; i < dictionary_count; i++)
    {
        int n = strlen(dictionary[i]);
        char *new_dec = (char *)calloc(n + 1, sizeof(char));
        strcpy(new_dec, dictionary[i]);
        qsort(new_dec, n, sizeof(char), compare_chars);
        dictionary[i] = new_dec;
    };

    qsort(dictionary, dictionary_count, sizeof(char *), compare);

    int *ans = (int *)calloc(query_count, sizeof(int));

    for (int i = 0; i < query_count; i++)
    {
        char **result = (char **)bsearch(query[i], dictionary, dictionary_count, sizeof(char *), compare_search);

        if (result == NULL)
        {
            continue;
        }

        ans[i] = 1;
        int index = (int)(result - dictionary);
        int left = index - 1;
        int right = index + 1;

        while (left >= 0 && !strcmp(dictionary[left], dictionary[index]))
        {
            left--;
            ++ans[i];
        }

        while (right < dictionary_count && !strcmp(dictionary[right], dictionary[index]))
        {
            right++;
            ++ans[i];
        }
    }

    *result_count = query_count;

    return ans;
}