class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        cnt = collections.Counter(nums)
        for i in range(1, 101):
            cnt[i] += cnt[i - 1]
        
        return [cnt[x - 1] for x in nums]