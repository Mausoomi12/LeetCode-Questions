/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
  var mappedArray = [];
  for (var i = 0; i < arr.length; i++) {
    mappedArray.push(fn(arr[i], i));
  }
  return mappedArray;
};