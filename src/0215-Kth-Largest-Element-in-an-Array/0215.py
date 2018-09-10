class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums_len = len(nums)
        l = 0
        r = nums_len - 1
        while l < r:
            tl = l
            tr = r
            tmp = nums[tl]
            while tl < tr:
                while tr > tl and nums[tr] > tmp:
                    tr -= 1
                if tr > tl:
                    nums[tl] = nums[tr]
                    tl += 1
                while tl < tr and nums[tl] <= tmp:
                    tl += 1
                if tl < tr:
                    nums[tr] = nums[tl]
                    tr -= 1
                
            nums[tl] = tmp
            if tl == nums_len - k:
                return tmp
            elif tl < nums_len - k:
                l = tl + 1
            else:
                r = tl - 1

        return nums[l]
        
if __name__ == "__main__":
    nums = [3,2,1,5,6,4]
    k = 2
    print(Solution().findKthLargest(nums, k))