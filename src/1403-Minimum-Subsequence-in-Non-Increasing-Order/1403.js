var minSubsequence = function(nums) {
    nums.sort((a, b) => a - b);
    let res = [], cur = 0, t = 0;
    
    for (let i of nums) t += i;
    t >>= 1;
    
    for (let i = nums.length - 1; i >= 0; i--) {
        cur += nums[i];
        res.push(nums[i]);
        if (cur > t) return res;
    }
    return res;
};