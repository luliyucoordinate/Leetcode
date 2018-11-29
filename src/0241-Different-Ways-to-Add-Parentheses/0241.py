class Solution:
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        mem = dict()
        return self._diffWaysToCompute(input, mem)
        
    def _diffWaysToCompute(self, input, mem):
        if input.isdigit():
            return [int(input)]
        
        if input in mem:
            return mem[input]
        
        res = list()
        for i in range(1, len(input)):
            if input[i] in "+-*":
                left = self._diffWaysToCompute(input[0:i], mem)
                right = self._diffWaysToCompute(input[i+1:], mem)
                for l in left:
                    for r in right:                      
                        res.append(self._calc(l, input[i], r))
                    
        mem[input] = res
        return res
        
    def _calc(self, a, op, b):
        return {
            '+': a + b,
            '-': a - b,
            '*': a * b
        }[op]