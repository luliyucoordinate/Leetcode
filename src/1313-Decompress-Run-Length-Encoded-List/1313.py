class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        return [x for a, b in zip(nums[0::2], nums[1::2]) for x in [b] * a]