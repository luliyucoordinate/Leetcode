class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        order = {v: i for i, v in enumerate(arr2)}
        return sorted(arr1 , key=lambda a: order.get(a, 1000 + a))