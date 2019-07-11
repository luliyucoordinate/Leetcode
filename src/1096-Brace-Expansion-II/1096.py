import itertools
class Solution:
    def braceExpansionII(self, expression):
        groups = [[]]
        level = 0
        for i, c in enumerate(expression):
            if c == '{':
                if level == 0:
                    start = i+1
                level += 1
            elif c == '}':
                level -= 1
                if level == 0:
                    groups[-1].append(self.braceExpansionII(expression[start:i]))
            elif level == 0:
                if c == ",":
                    groups.append([])
                else:
                    groups[-1].append([c])
                
        return sorted(set().union(*[set(map(''.join, itertools.product(*group))) for group in groups]))