import operator
class Solution:
    def parseBoolExpr(self, s: str) -> bool:
        u = 0
            
        def f1(op):
            nonlocal u
            u += 2
            res = op(True if op == operator.__and__ else False, f())
            while s[u] != ')':
                u += 1
                res = op(res, f())
            u += 1
            return res

        def f2():
            nonlocal u
            u += 2
            res = not f()
            u += 1
            return res
        
        def f():
            nonlocal u
            if s[u] == 't':
                u += 1
                return True
            elif s[u] == 'f':
                u += 1
                return False
            elif s[u] == '&':
                return f1(operator.__and__)
            elif s[u] == '|':
                return f1(operator.__or__)
            else:
                return f2()
        
        return f()