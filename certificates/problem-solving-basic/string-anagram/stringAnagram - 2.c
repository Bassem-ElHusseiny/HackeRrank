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

    // Frequency Array //
    int size = 1;
    char **freq_dec = (char **)calloc(size, sizeof(char *));
    int *freq = (int *)calloc(size, sizeof(int));
    freq[0] = 1;
    freq_dec[0] = dictionary[0];

    for (int i = 0; i < dictionary_count - 1; i++)
    {

        if (!strcmp(dictionary[i], dictionary[i + 1]))
        {
            ++freq[size - 1];
            continue;
        }

        freq_dec = (char **)realloc(freq_dec, ++size * sizeof(char *));
        freq_dec[size - 1] = dictionary[i + 1];
        freq = (int *)realloc(freq, size * sizeof(int));
        freq[size - 1] = 1;
    }

    int *ans = (int *)calloc(query_count, sizeof(int));

    for (int i = 0; i < query_count; i++)
    {
        char **result = (char **)bsearch(query[i], freq_dec, size, sizeof(char *), compare_search);

        if (result == NULL)
        {
            continue;
        }

        int index = (int)(result - freq_dec);
        ans[i] = freq[index];
    }

    *result_count = query_count;

    return ans;
}