var constrainedSubsetSum = function(nums, k) {
    let q = [], res = -10000, n = nums.length;

    for (let i = 0; i < n; i++) {
        nums[i] = Math.max(nums[i], nums[i] + (q.length ? q[0] : 0));
        while (q.length && nums[i] > q[q.length - 1]) q.pop();
        q.push(nums[i]);

        if (i >= k && q.length && q[0] == nums[i - k]) q.shift();
        res = Math.max(res, nums[i]);
    }
    return res;
};