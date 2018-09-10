class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        for i in range(ord('a'), ord('z')+1):
            if s.count(chr(i)) != t.count(chr(i)):
                return False
        return True

        
if __name__ == "__main__":
    s = "anagram"
    t = "nagaram"
    print(Solution().isAnagram(s, t))