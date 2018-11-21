class Solution:
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        minv, maxv = 0, len(S)
        result = list()
        for ch in S:
            if ch == 'I':
                result.append(minv)
                minv += 1
            elif ch == 'D':
                result.append(maxv)
                maxv -= 1
        result.append(maxv)    
        return result

if __name__ == "__main__":
    S = "IDID"
    print(Solution().diStringMatch(S))