/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
    let max_right = -1;
    for (let i = arr.length - 1; i >= 0; i--) {
        max_right = Math.max(arr[i], arr[i] = max_right);
    }
    return arr;
};