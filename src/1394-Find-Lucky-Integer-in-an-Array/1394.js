var findLucky = function(arr) {
    let cnt = new Array(501).fill(0);
    for (let i of arr) cnt[i]++;

    for (let i = 500; i > 0; i--) {
        if (cnt[i] == i) return i;
    }
    return -1;
};