class Solution:
    def brokenCalc(self, X: 'int', Y: 'int') -> 'int':
        if X >= Y:
            return X - Y
        return 1 + self.brokenCalc(X, Y + 1 if Y % 2 else Y // 2)