var findBestValue = function(arr, target) {
    arr.sort((a, b) => b - a);
    let maxv = arr[0];
    while (arr != false && target >= arr[arr.length-1]*arr.length) {
        target -= arr.pop();
    }
    return arr != false ? Math.floor(target/arr.length + 0.49) : maxv;
};