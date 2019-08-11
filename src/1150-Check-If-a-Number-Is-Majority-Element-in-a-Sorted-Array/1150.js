var isMajorityElement = function(nums, target) {
    var cnt = 0;
    for (let i of nums) if (target == i) cnt++;
    return cnt > nums.length/2;
};