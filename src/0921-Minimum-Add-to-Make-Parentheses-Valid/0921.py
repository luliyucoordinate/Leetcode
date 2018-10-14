class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        result, tmp, = 0, 0
        for s in S:
            tmp += 1 if s == '(' else -1
            if tmp == -1:
                result += 1
                tmp += 1

        return result + tmp

if __name__ == "__main__":
    S = ""
    print(Solution().minAddToMakeValid(S))