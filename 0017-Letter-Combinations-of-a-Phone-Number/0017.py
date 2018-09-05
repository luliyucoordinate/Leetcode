# class Solution:
#     def __init__(self):
#         self.letterMap = [
#             ' ',
#             '',
#             'abc',
#             'def',
#             'ghi',
#             'jkl',
#             'mno',
#             'pqrs',
#             'tuv',
#             'wxyz'
#         ]
#     def findCombination(self, digits, index, s, res):
#         if index == len(digits):
#             res.append(s)
#             return 

#         char = digits[index]
#         letters = self.letterMap[ord(char) - ord('0')]
#         for letter in letters:
#             self.findCombination(digits, index + 1, s + letter, res)

#     def letterCombinations(self, digits):
#         """
#         :type digits: str
#         :rtype: List[str]
#         """
#         result = list()
#         if not digits:
#             return result
            
#         self.findCombination(digits, 0, "", result)
#         return result
import itertools
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        
        l_map = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', 
                 '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        
        chars = [l_map.get(d) for d in digits]
        return [''.join(x) for x in itertools.product(*chars)]