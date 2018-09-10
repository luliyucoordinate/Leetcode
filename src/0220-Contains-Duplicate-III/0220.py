class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        for i, a in enumerate(nums):
            for j, b in enumerate(nums):
                if i != j and abs(i - j) <= k and abs(a - b) <= t:
                    return True

        return False
        

if __name__ == "__main__":
    nums = [4,2]
    k = 2
    t = 1
    print(Solution().containsNearbyAlmostDuplicate(nums, k, t))