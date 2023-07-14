function countPairs(arr) {
  let maxSize = 2 ** 12;
  let arrCount = new Array(maxSize).fill(0);

  for (const x of arr) {
    arrCount[x] += 1;
  }

  let ans = 0;
  let andOp = 0
  for (let i = 0; i < arrCount.length; i++) {
    for (let j = i; j < arrCount.length; j++) {
      andOp = i & j;
      if (andOp && (!(andOp & (andOp - 1)))) {
        if (i === j) {
          ans += (arrCount[i] * (arrCount[i] - 1)) / 2;
        } else {
          ans += arrCount[i] * arrCount[j];
        }
      }
    }
  }
  return ans;
}