function update(x, val, arr) {
  while (x < arr.length) {
    arr[x] += val;
    x += x & (-x);

  }
}

function prefixSum(x, arr) {
  let sum = 0;
  while (x > 0) {
    sum += arr[x]
    x -= x & (-x);
  }
  return sum;
}

function sortedSum(a) {
  const maxNumber = 10 ** 6;
  const modulo = (10 ** 9) + 7;
  let index = new Array(maxNumber + 1).fill(0);
  let preSum = new Array(maxNumber + 1).fill(0);
  let sum = 0, order = 0, diff = 0;
  let acc = 0, ans = 0;
  for (let i = 0; i < a.length; i++) {
    order = prefixSum(a[i], index) + 1;
    diff = sum - prefixSum(a[i], preSum);
    acc = acc + order * a[i] + diff;
    ans += acc % modulo;
    sum += a[i];
    update(a[i], 1, index);
    update(a[i], a[i], preSum);
  }
  return ans % modulo;
}