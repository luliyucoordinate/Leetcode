class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        max_right = -1
        for i in range(len(arr) - 1, -1, -1):
            arr[i], max_right = max_right, max(max_right, arr[i])
        return arr