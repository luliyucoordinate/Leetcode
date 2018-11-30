class Solution:
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        def helper(i, j, k, mem):
            if (i, j) in mem:
                return mem[(i, j)]
            
            if k == len(s3):
                return True
            
            if i < len(s1) and s1[i] == s3[k]:
                if (helper(i+1, j, k + 1, mem)):
                    mem[(i, j)] = True
                    return True
                
            if j < len(s2) and s2[j] == s3[k]:
                if helper(i, j+1, k+1, mem):
                    mem[(i, j)] = True
                    return True
                
            mem[(i, j)] = False
            return False
        
        if len(s1)+len(s2) != len(s3):
            return False
        
        return helper(0, 0, 0, {})