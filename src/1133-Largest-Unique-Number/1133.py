class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        cnt = collections.Counter(A)
        sCnt = sorted(cnt.items(), key=lambda a:(a[1], -a[0]))
        if sCnt[0][1] != 1:
            return -1
        return sCnt[0][0]