function getMinCost(crew_id, job_id) {
  crew_id.sort((a, b) => a - b);
  job_id.sort((a, b) => a - b);
  let totalDistance = 0;
  for (let i = 0; i < crew_id.length; i++) {
    totalDistance += Math.abs(crew_id[i] - job_id[i]);

  }
  return totalDistance;
}
