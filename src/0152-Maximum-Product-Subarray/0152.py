class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_len = len(nums)
        loc_min, loc_max = [0]*2, [0]*2
        loc_min[0] = loc_max[0] = glb_max = nums[0]
        for i in range(1, nums_len):
            loc_min[1] = min(loc_max[0]*nums[i], loc_min[0]*nums[i], nums[i])
            loc_max[1] = max(loc_max[0]*nums[i], loc_min[0]*nums[i], nums[i])
            loc_min[0], loc_max[0] = loc_min[1], loc_max[1]
            glb_max = max(loc_max[1], glb_max)

        return glb_max
        
if __name__ == "__main__":
    nums = [0,-2]
    print(Solution().maxProduct(nums))