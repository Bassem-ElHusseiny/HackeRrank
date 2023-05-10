function decryptPassword(s) {
  let newS = "";
  let j = 0;
  for (let i = 0; i < s.length; i++) {
    if (Number.isInteger(Number(s[i])) && s[i] !== "0") {
      j++;
      continue;
    }
    if ((i < s.length - 2) && s[i + 2] === "*") {
      newS += s[i + 1] + s[i];
      i += 2;
    }
    else if (s[i] === "0") {
      newS += s[j - 1];
      j--;
    } else {
      newS += s[i];
    }

  }

  return newS;
}