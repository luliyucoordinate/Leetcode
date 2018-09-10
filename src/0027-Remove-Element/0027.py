class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k = 0
        for i, num in enumerate(nums):
            if num != val:
                if i != k:
                    nums[k] = num
                    k += 1
                else: #i == k
                    k += 1

        return k

if __name__ == "__main__":
    nums = [3, 2, 2, 3]
    val = 2
    print(Solution().removeElement(nums, val))