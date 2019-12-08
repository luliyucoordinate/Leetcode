from functools import reduce
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        A = list(map(int, str(n)))
        return reduce(operator.mul, A) - sum(A)