function findSubstring(s, k) {
  let vowels = ["a", "e", "i", "o", "u"];
  let count = 0;
  let ans = 0;

  let key = {};
  for (let x of vowels) {
    key[x] = 1;
  }

  for (let i = 0; i < k; i++) {
    count += (key[s[i]] || 0);
  }
  let max = count;

  for (let i = k; i < s.length; i++) {
    count += (key[s[i]] || 0);
    count -= (key[s[i - k]] || 0);
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