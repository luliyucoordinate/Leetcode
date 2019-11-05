var isGoodArray = function(nums) {
    let x = nums[0], y;
    for (let a of nums) {
        while (a > 0) {
            y = x % a;
            x = a;
            a = y;
        }
    }
    return x == 1;
};