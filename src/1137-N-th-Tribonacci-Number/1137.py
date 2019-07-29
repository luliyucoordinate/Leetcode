class Solution:
    d = dict()
    def tribonacci(self, n: int) -> int:
        def tri(x):
            n, a, b, c = 0, 0, 1, 1
            while n < x:
                yield a + b + c
                a, b, c = b, c, a + b + c
                n += 1
                
        if n in self.d:
            return self.d[n]
        
        for i, v in enumerate(tri(35)):
            self.d[i + 3] = v
        self.d[0], self.d[1], self.d[2] = 0, 1, 1
        return self.d[n]