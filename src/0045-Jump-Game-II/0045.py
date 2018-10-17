class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_len = len(nums)       
        steps, step = [nums[0]]*nums_len, 0
        for i in range(1, nums_len):
            if steps[step] >= nums_len - 1:
                return step + 1
            if steps[step + 1] < i + nums[i]:
                steps[step + 1] = i + nums[i] 
            if steps[step] <= i:
                step += 1  
                
        return step
if __name__ == "__main__":
    nums = [1,2,3]
    print(Solution().jump(nums))