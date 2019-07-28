class Solution:
    def isArmstrong(self, N: int) -> bool:
        n = len(str(N))
        return sum(pow(int(d), n) for d in str(N)) == N