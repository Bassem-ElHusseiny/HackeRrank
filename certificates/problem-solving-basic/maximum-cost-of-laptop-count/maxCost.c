#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxCost(int cost_count, int* cost, int labels_count, char** labels, int dailyCount) 
{
  int maxcost = 0;
  int sumcost = 0;
  int count = 0;
  for (int i = 0; i < labels_count; i++)
  {
    if (!strcmp(labels[i], "legal"))
    {
      count++;
    }
    sumcost += cost[i];
    if (count == dailyCount)
    {
      maxcost = maxcost > sumcost ? maxcost : sumcost;
      sumcost = 0;
      count = 0;
    }
  }

  return maxcost;
}