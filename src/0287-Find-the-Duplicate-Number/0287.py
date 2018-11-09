class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low, high = 1, len(nums)-1
        
        while low < high:
            mid = (high+low)//2
            count = sum(num <= mid for num in nums)
            if count <= mid:
                low = mid+1
            else:
                high = mid
        return low

if __name__ == "__main__":
    nums = [1,3,4,2,2,2]
    print(Solution().findDuplicate(nums))