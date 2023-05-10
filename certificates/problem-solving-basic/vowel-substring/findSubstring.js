function findSubstring(s, k) {
  let vowels = ["a", "e", "i", "o", "u"];
  let count = 0;
  let ans = 0;

  for (let i = 0; i < k; i++) {
    count += vowels.includes(s[i]);
  }
  let max = count;

  for (let i = k; i < s.length; i++) {
    count += vowels.includes(s[i]);
    count -= vowels.includes(s[i - k]);
    if (count > max) {
      max = count;
      ans = i - k + 1;
    }
  }
  if (max > 0) {
    return s.slice(ans, ans + k);
  }

  return "Not found!";
}