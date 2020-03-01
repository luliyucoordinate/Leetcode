var smallerNumbersThanCurrent = function(nums) {
    let cnt = new Array(101).fill(0), res = [];
    for (let i of nums) cnt[i]++;

    for (let i = 1; i <= 100; i++) {
        cnt[i] += cnt[i - 1];    
    }

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == 0) res[i] = 0;
        else res[i] = cnt[nums[i] - 1];
    }
    return res;  
};