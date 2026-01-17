function elementadder(arr, item) {
  arr.push(item);
  var removed = arr.shift();
  return removed;
}

var Array1 = [1, 2, 3, 4, 5];
var g = elementadder(Array1, 6);
console.log(g);
