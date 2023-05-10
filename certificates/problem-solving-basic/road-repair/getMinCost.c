#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(int *a, int *b)
{
  return *b - *a;
}
long getMinCost(int crew_id_count, int* crew_id, int job_id_count, int* job_id)
{
  qsort(crew_id, crew_id_count, sizeof(int), compare);
  qsort(job_id, job_id_count, sizeof(int), compare);

  long totalDistance = 0;
  for (int i = 0; i < crew_id_count; i++)
  {

    totalDistance += abs(crew_id[i] - job_id[i]);
  }

  return totalDistance;
}
