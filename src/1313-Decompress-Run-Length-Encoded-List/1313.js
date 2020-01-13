var decompressRLElist = function(nums) {
    let res = [];
    for (let i = 0; i < nums.length; i += 2) {
        for (let j = 0; j < nums[i]; j++) {
            res.push(nums[i + 1]);
        }
    }
    return res;
};