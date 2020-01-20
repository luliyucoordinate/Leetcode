class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums) 
        pre, cur, step = -1, 0, 0
        for i in range(n):
            if cur >= n - 1: 
                return step
            elif pre < i <= cur:
                step, pre = step + 1, cur
            cur = max(cur, i + nums[i])     
        return step
        
if __name__ == "__main__":
    nums = [1,2,3]
    print(Solution().jump(nums))