class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        change, tmp, n = True, arr[:], len(arr)
        while change:
            change = False
            for i in range(1, n - 1):
                if arr[i - 1] < arr[i] > arr[i + 1]:
                    tmp[i] -= 1
                    change = True
                elif arr[i - 1] > arr[i] < arr[i + 1]:
                    tmp[i] += 1
                    change = True
            arr = tmp[:]
        return arr