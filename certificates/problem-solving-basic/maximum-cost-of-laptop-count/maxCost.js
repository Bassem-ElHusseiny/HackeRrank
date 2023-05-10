function maxCost(cost, labels, dailyCount) {

  let maxcost = 0;
  let sumcost = 0;
  let count = 0

  for (let i = 0; i < cost.length; i++) {
    if (labels[i] === "legal") {
      count++;

    }

    sumcost += cost[i];

    if (count == dailyCount) {
      maxcost = Math.max(maxcost, sumcost);

      sumcost = 0;
      count = 0;
    }
  }

  return maxcost;
}
