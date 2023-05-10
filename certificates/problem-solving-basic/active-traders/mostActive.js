function mostActive(customers) {
  let d = {};
  let outArr = [];

  for (let i of customers) {
    d[i] = (d[i] || 0) + 1;
  }

  return Object.keys(d)
    .filter((v) => {
      return d[v] >= 0.05 * customers.length;
    }).sort();
}
