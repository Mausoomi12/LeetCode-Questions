/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    const stack = [arr]; // Initialize a stack with the input array

  while (stack.length) {
    const element = stack.pop(); // Pop the last element from the stack

    if (Array.isArray(element)) {
      // If the element is an array, iterate over its elements in reverse order
      for (let i = element.length - 1; i >= 0; i--) {
        stack.push(element[i]); // Push each element to the stack
      }
    } else {
      yield element; // Yield the integer element
    }
  }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */