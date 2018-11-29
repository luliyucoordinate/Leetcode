class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        mem = [0]*(n+1)
        mem[0], mem[1] = 1, 1
        
        for i in range(2, n + 1):
            for j in range(1, i + 1):
                mem[i] += mem[j - 1]*mem[i - j]
                
        return mem[-1]

if __name__ == "__main__":
    n = 4
    print(Solution().numTrees(n))