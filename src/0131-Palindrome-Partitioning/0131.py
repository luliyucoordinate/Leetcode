# class Solution:
#     def _partition(self, s, index, t, result):
#         if index == len(s):
#             result.append(t.copy())
#             return 

#         def isPartition(st):
#             return st[::-1] == st

#         for i in range(index+1, len(s)+1):
#             if isPartition(s[index:i]):
#                 t.append(s[index:i])
#                 self._partition(s, i, t, result)
#                 t.pop()
        
#     def partition(self, s):
#         """
#         :type s: str
#         :rtype: List[List[str]]
#         """
#         result = list()
#         if not s:
#             return result
        
#         self._partition(s, 0, list(), result)
#         return result

class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        results = [[s[0]]]
        for c in s[1:]:
            for r in results:
                r.append(c)
                
            extra = []
            for r in results:
                if len(r) > 1:
                    p = r[-2] + r[-1]
                    if p == p[::-1]:
                        extra.append(r[:-2] + [p])
                    elif len(r) > 2:
                        p = r[-3] + r[-2] + r[-1]
                        if p == p[::-1]:
                            extra.append(r[:-3] + [p])
                            
            results.extend(extra)
        return results       

if __name__ == '__main__':
    s = "aab"
    print(Solution().partition(s))