class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums_hash = {}
        result = list()
        for num in nums:
            nums_hash[num] = nums_hash.get(num, 0) + 1
        if 0 in nums_hash and nums_hash[0] >= 3:
            result.append([0, 0, 0])

        neg = list(filter(lambda x: x < 0, nums_hash))
        pos = list(filter(lambda x: x>= 0, nums_hash))

        for i in neg:
            for j in pos:
                dif = 0 - i - j
                if dif in nums_hash:
                    if dif in (i, j) and nums_hash[dif] >= 2:
                        result.append([i, j, dif])
                    if dif < i or dif > j:
                        result.append([i, j, dif])
                    
        return result

if __name__ == '__main__':
    nums = [3,0,-2,-1,1,2]
    print(Solution().threeSum(nums))