class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.lstrip().rstrip()
        e, point, num = False, False, False
        i, s_len = 0, len(s)
        
        if s_len > 0 and s[i] in '+-':
            i += 1
            
        while i < s_len:
            c = s[i]
            if c in '0123456789':
                i += 1
                num = True
                continue
            elif c in 'eE':
                if not num or e or i == s_len - 1:
                    return False
                e = True
                if s[i+1] in '+-' and i < s_len - 2:
                    i += 1   
            elif c == '.':
                if point or e:
                    return False
                point = True
            else:
                return False                

            i += 1
        return num