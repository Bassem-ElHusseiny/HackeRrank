function findSum(numbers, queries) {
  let a = [0];
  let b = [0];
  for (let x of numbers) {
    a.push(a[a.length - 1] + x);
    b.push(b[b.length - 1] + (x == 0));
  }
  return queries.map(([l, r, x]) => a[r] - a[l - 1] + x * (b[r] - b[l - 1])
  );
}