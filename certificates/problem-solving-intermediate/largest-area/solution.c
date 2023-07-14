#include <stdlib.h>

typedef struct Node
{
    int l, r, val;
    struct Node *lc;
    struct Node *rc;
} Node;

Node *createNode(int left, int right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->l = left;
    node->r = right;
    node->lc = NULL;
    node->rc = NULL;
    node->val = right - left;
    return node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void split(Node *node, int x)
{
    if (x == node->l || x == node->r)
    {
        return;
    }

    if (node->lc)
    {
        if (x < node->lc->r)
        {
            split(node->lc, x);
        }
        else
        {
            split(node->rc, x);
        }
        node->val = max(node->lc->val, node->rc->val);
    }
    else
    {
        node->lc = createNode(node->l, x);
        node->rc = createNode(x, node->r);
        node->val = max(x - node->l, node->r - x);
    }
}

long *getMaxArea(int w, int h, int isVertical_count, bool *isVertical, int distance_count, int *distance, int *result_count)
{
    Node *w_root = createNode(0, w);
    Node *h_root = createNode(0, h);

    long *ans = (long *)malloc(isVertical_count * sizeof(long));

    for (int i = 0; i < isVertical_count; i++)
    {
        if (isVertical[i])
        {
            split(w_root, distance[i]);
        }
        else
        {
            split(h_root, distance[i]);
        }
        ans[i] = (long)w_root->val * h_root->val;
    }

    *result_count = isVertical_count;
    return ans;
}