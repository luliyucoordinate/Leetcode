class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []

        c1, c2, m, n = 0, 0, None, None
        for num in nums:
            if num == m:
                c1 += 1
            elif num == n:
                c2 += 1
            elif c1 == 0:
                m, c1 = num, 1
            elif c2 == 0:
                n, c2 = num, 1
            else:
                c1 -= 1
                c2 -= 1

        return [num for num in set([m, n]) \
                    if nums.count(num) > len(nums)//3]
        

if __name__ == "__main__":
    nums = [0, -1, 2, 2, -1]
    print(Solution().majorityElement(nums))