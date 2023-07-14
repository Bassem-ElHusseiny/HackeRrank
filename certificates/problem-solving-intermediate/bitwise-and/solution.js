function countPairs(arr) {
  const d = {};
  for (const x of arr) {
    d[x] = (d[x] || 0) + 1;
  }
  const dArray = Object.entries(d);
  let ans = 0;
  let andOp = 0;
  for (let i = 0; i < dArray.length; i++) {
    const [x, x_Count] = dArray[i];
    for (let j = i; j < dArray.length; j++) {
      const [y, y_Count] = dArray[j];
      andOp = x & y;
      if (andOp && (!(andOp & (andOp - 1)))) {
        if (x === y) {
          ans += (x_Count * (x_Count - 1)) / 2;
        } else {
          ans += x_Count * y_Count;
        }
      }
    }
  }
  return ans;
}