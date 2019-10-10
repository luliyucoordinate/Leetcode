var longestSubsequence = function(arr, dif) {
    let mem = new Map(), res = 1;
    for (let i of arr) {
        if (mem.has(i - dif)) mem.set(i, mem.get(i - dif) + 1);
        else mem.set(i, 1);
        res = Math.max(res, mem.get(i));
    }
    return res;
};