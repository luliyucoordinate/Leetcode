class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        
        def check(x):
            l, r = 0, len(arr2) - 1
            while l < r:
                mid = (l + r) >> 1
                if abs(arr2[mid] - x) <= d: return False
                if arr2[mid] > x:
                    r = mid
                else:
                    l = mid + 1
            return abs(arr2[l] - x) > d
        return sum(check(x) for x in arr1)