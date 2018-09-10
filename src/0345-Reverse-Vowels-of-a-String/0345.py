class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ['a', 'u', 'e', 'i', 'o', 'A', 'U', 'E', 'I', 'O']
        l = 0
        r = len(s) - 1
        s = list(s)
        while l < r:
            if s[l] not in vowels:
                l += 1
                continue

            if s[r] not in vowels:
                r -= 1
                continue

            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1
        return ''.join(s)


if __name__ == "__main__":
    s = "hello"
    print(Solution().reverseVowels(s))