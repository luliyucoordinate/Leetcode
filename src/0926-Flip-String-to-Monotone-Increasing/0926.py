
class Solution:
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
        m, n = 0, 0
        for s in S:
            m += int(s)
            n = min(m, n + 1 - int(s))
        return n

if __name__ == "__main__":
    s = "11011"
    print(Solution().minFlipsMonoIncr(s))
