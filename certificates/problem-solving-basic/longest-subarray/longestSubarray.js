function longestSubarray(arr) {

  let x = 1;
  let y = 1;
  let max = 1;

  for (let i = 1; i < arr.length; i++) {
    if (arr[i - 1] == arr[i]) {
      x++;
      y++;
    } else if (arr[i - 1] == (arr[i] - 1)) {
      x = y + 1;
      y = 1;

    } else if (arr[i - 1] == (arr[i] + 1)) {
      y = x + 1;
      x = 1;
    } else {
      x = y = 1;
    };
    max = Math.max(max, x, y);
  }
  return max;
}