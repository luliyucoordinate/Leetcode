var transformArray = function(arr) {
    let change = true, tmp = arr.slice();
    while (change) {
        change = false;
        for (let i = 1; i < arr.length -1; i++) {
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                tmp[i]--; change = true;
            } else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                tmp[i]++; change = true;
            } 
        }
        arr = tmp.slice();
    }
    return arr;
};