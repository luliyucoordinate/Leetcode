class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = 0
        for i, num in enumerate(nums):
            if k < 2 or num != nums[k - 2]:
                if i != k:
                    nums[k] = num 
                    k += 1
                else:
                    k += 1

        return k

if __name__ == "__main__":
    nums = [0,0,1,1,1,1,2,3,3]
    print(Solution().removeDuplicates(nums))
    print(nums)