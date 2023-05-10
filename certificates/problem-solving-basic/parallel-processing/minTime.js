function minTime(files, numCores, limit) {
  let max = [];
  let total = 0;
  for (let i = 0; i < files.length; i++) {
    if ((files[i] % numCores) == 0) {
      max.push(files[i]);

    } else {
      total += files[i];
    }
  }

  max.sort((a, b) => b - a);
  for (let i = 0; i < max.length; i++) {
    if (i < limit) {
      total += (max[i] / numCores);

    } else {
      total += max[i];
    }

  }

  return total;
}