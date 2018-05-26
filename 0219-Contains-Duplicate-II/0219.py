class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        record = list()
        for i, num in enumerate(nums):
            if num in record:
                return True

            record.append(num)

            if len(record) == k + 1:
                record.remove(nums[i - k]) 

        return False


if __name__ == "__main__":
    points = [1,0,1,1]
    k = 1
    print(Solution().containsNearbyDuplicate(points, k))