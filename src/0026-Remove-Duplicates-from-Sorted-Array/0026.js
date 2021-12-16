/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
  nums.forEach((element, i) => {
    if (element == nums[i + 1]) {
      nums.splice(i + 1, 1)
      removeDuplicates(nums);
    }
  });
  return nums.length;
};
