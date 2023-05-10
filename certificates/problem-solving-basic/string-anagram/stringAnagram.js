function stringAnagram(dictionary, query) {
  let result = [];
  let str = {};
  for (let i = 0; i < dictionary.length; i++) {
    dictionary[i] = dictionary[i].split("").sort().join("");
    str[dictionary[i]] = (str[dictionary[i]] || 0) + 1
  }

  for (let i = 0; i < query.length; i++) {
    query[i] = query[i].split("").sort().join("");
    result.push(str[query[i]] || 0);
  }

  return result;
}
