function filledOrders(order, k) {

  let total = 0;
  order.sort((a, b) => a - b);
  for (let i = 0; i < order.length; i++) {
    if (order[i] <= k) {
      total++
      k -= order[i];
    } else {
      break;
    }

  }

  return total;
}