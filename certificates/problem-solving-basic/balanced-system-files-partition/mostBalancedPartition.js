function mostBalancedPartition(parent, files_size) {
  for (let i = parent.length - 1; i > 0; i--) {
    files_size[parent[i]] += files_size[i];
  }

  let mindiff = files_size[0];
  for (let i = 1; i < parent.length; i++) {
    let diff = Math.abs(files_size[0] - 2 * files_size[i]);
    if (diff < mindiff) {
      mindiff = diff;
    }
  }

  return mindiff;
}