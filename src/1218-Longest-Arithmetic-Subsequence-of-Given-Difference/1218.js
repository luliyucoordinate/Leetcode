var longestSubsequence = function(arr, dif) {
    let mem = {}, res = 1;
    for (let i of arr) {
        if (mem[i - dif]) mem[i] = mem[i - dif] + 1;
        else mem[i] = 1;
        res = Math.max(res, mem[i]);
    }
    return res;
};