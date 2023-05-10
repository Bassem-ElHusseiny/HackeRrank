function nearlySimilarRectangles(rectangles) {
  const gcd = function (a, b) {
    return b > 0 ? gcd(b, a % b) : a;
  };
  
  const d = {};
  for (const [w, h] of rectangles) {
    const z = gcd(w, h);
    const key = `${w / z},${h / z}`;
    d[key] = (d[key] || 0) + 1;
  }

  return Object.values(d).reduce((acc, x) => acc + (x * (x - 1)) / 2, 0);
}
