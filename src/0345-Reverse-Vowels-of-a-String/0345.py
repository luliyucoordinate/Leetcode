class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = set(['a', 'u', 'e', 'i', 'o', 'A', 'U', 'E', 'I', 'O'])
        p = [i for i in s if i in vowels]
        return ''.join([i if i not in vowels else p.pop() for i in s])

if __name__ == "__main__":
    s = "hello"
    print(Solution().reverseVowels(s))