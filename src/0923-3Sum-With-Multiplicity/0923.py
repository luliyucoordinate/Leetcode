from collections import Counter
class Solution:
    def threeSumMulti(self, A, target):
        """
        :type A: List[int]
        :type target: int
        :rtype: int
        """
        c = Counter(A)
        result = 0
        for i, x in c.items():
            for j, y in c.items():
                k = target - i - j
                if k not in c:
                    continue
                if i == j == k: 
                    result += x * (x - 1) * (x - 2) // 6
                elif i == j != k: 
                    result += x * (x - 1) // 2 * c[k]
                elif i < j and j < k: 
                    result += x * y * c[k]

        return result % (10**9 + 7)

if __name__ == "__main__":
    A = [1,2,3,3,1]
    target = 5
    print(Solution().threeSumMulti(A, target))