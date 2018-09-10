class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums_sort = sorted(nums)
        for i, _ in enumerate(nums_sort[:-1]):
            if nums_sort[i] == nums_sort[i + 1]:
                return True
        
        return False

if __name__ == "__main__":
    nums = [1,2,3,1]
    print(Solution().containsDuplicate(nums))