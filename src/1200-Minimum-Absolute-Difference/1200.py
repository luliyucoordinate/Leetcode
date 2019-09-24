class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        res, min_dif = [], float("inf")
        for i in range(1, len(arr)):
            dif = arr[i] - arr[i-1]
            if dif > min_dif:
                continue
            elif dif < min_dif:
                min_dif, res = dif, []    
            res.append([arr[i-1], arr[i]])
        return res