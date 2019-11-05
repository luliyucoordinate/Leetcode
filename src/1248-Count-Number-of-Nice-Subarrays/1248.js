var numberOfSubarrays = function(nums, k) {
    let atMost = function(k) {
        let res = 0, i = 0;
        for (let j = 0; j < nums.length; j++) {
            k -= nums[j] % 2;
            while (k < 0) {
                k += nums[i++] % 2;
            }
            res += j - i + 1;
        }
        return res;
    }
    return atMost(k) - atMost(k - 1);
};