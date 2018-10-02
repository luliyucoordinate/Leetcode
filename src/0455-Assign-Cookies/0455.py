class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort(reverse=True)
        s.sort(reverse=True)
        g_index, s_index, result = 0, 0, 0

        while g_index < len(g) and s_index < len(s):
            if s[s_index] >= g[g_index]:
                result += 1
                s_index += 1
                g_index += 1
            else:
                g_index += 1

        return result


if __name__ == "__main__":
    g = [1,2,3]
    s = [1,1]
    print(Solution().findContentChildren(g, s))