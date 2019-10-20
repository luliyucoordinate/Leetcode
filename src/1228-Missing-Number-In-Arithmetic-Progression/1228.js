var missingNumber = function(arr) {
    let A = 0;
    for (let a of arr) A += a;
    return Math.floor((arr[0] + arr[arr.length - 1]) * (arr.length + 1)/2) - A;
};