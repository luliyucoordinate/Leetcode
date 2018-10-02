class Solution:
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        for per_s in s:
            s_index_t = t.find(per_s)
            if s_index_t == -1:
                return False

            if s_index_t == len(t) - 1:
                t = str()
            else:
                t = t[s_index_t+1:]

        return True

if __name__ == "__main__":
    s = "axc"
    t = "ahbgdc"
    print(Solution().isSubsequence(s, t))