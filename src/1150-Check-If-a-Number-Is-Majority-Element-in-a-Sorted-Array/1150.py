class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        return collections.Counter(nums)[target] > len(nums)/2