class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        l1, l2 = len(arr1), len(arr2)
        arr2.sort()
        
        dp = {0: arr1[0], 1: arr2[0]}
        for i in range(1, l1):
            new_dp = {}
            for key in dp:
                if arr1[i] > dp[key] and (key not in new_dp or new_dp[key] > arr1[i]):
                    new_dp[key] = arr1[i]
                j = bisect.bisect(arr2, dp[key])
                if j < l2 and (key + 1 not in new_dp or new_dp[key + 1] > arr2[j]):
                    new_dp[key+1] = arr2[j]
            dp = new_dp
        if len(dp) == 0:
            return -1
        return min(dp.keys())