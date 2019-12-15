class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        for i in range(0, n, n//4 + 1):
            if bisect.bisect(arr, arr[i]) - bisect.bisect_left(arr, arr[i]) > n//4 : 
                return arr[i]