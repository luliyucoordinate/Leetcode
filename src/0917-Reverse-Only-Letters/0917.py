class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        p = [i for i in S if i.isalpha()]
        return ''.join([i if not i.isalpha() else p.pop() for i in S])

if __name__ == "__main__":
    S = "a-bC-dEf-ghIj"
    print(Solution().reverseOnlyLetters(S))