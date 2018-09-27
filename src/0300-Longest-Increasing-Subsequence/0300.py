class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mem = list()
        len_nums = len(nums)
        for i in range(len_nums):
            low, upper = 0, len(mem)
            while low < upper:
                mid = (upper - low)//2 + low
                if mem[mid] < nums[i]:
                    low = mid + 1
                else:
                    upper = mid

            if upper == len(mem):
                mem.append(nums[i])
            else:
                mem[upper] = nums[i]
        
        return len(mem)

if __name__ == '__main__':
    nums = [10,9,2,5,3,7,101,18]
    print(Solution().lengthOfLIS(nums))