import string
class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        p = [i for i in S if i in string.ascii_letters]
        return ''.join([i if i not in string.ascii_letters else p.pop() for i in S])

if __name__ == "__main__":
    S = "a-bC-dEf-ghIj"
    print(Solution().reverseOnlyLetters(S))