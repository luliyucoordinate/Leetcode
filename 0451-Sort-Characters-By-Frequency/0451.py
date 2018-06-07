class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ''.join(c*-n for n,c in sorted((-s.count(c),c)for c in set(s)))
   

if __name__ == "__main__":
    s = "abcc"
    print(Solution().frequencySort(s))