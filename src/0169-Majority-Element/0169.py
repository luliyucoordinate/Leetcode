class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return nums[len(nums)//2]
        
if __name__ == "__main__":
    nums = [2,2,1,1,1,2,2]
    print(Solution().majorityElement(nums))