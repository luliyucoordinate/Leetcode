var movesToMakeZigzag = function(nums) {
    var res = [0, 0];
    nums.unshift(Number.MAX_VALUE);
    nums.push(Number.MAX_VALUE);
    for (var i = 1; i < nums.length - 1; ++i) {
        res[i % 2] += Math.max(0, nums[i] - Math.min(nums[i-1], nums[i+1]) + 1);
    }
    return Math.min(res[0], res[1]);
};