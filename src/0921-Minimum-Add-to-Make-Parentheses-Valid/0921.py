class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        right, left, = 0, 0
        for s in S:
            left += 1 if s == '(' else -1
            if left == -1:
                right += 1
                left += 1

        return right + left

if __name__ == "__main__":
    S = ""
    print(Solution().minAddToMakeValid(S))