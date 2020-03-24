var createTargetArray = function(nums, index) {
    let res = [];
    for (let i = 0; i < nums.length; i++) {
        res.splice(index[i], 0, nums[i]);
    }
    return res;
};