var longestSubarray = function(nums, limit) {
    let maxq = [], minq = [], i = 0;

    for (let a of nums) {
        while (maxq.length > 0 && a > maxq[maxq.length - 1]) maxq.pop();
        while (minq.length > 0 && a < minq[minq.length - 1]) minq.pop();
        maxq.push(a);
        minq.push(a);

        if (maxq[0] - minq[0] > limit) {
            if (maxq[0] == nums[i]) maxq.shift();
            if (minq[0] == nums[i]) minq.shift();
            i++;
        }
    }
    return nums.length - i;
};