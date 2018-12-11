class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        factorials = [1]*(n+1)
        for i in range(1, n+1):
            factorials[i] = factorials[i-1]*i
            
        n_list = [i for i in range(1, n+1)]
        return self.helper(n, k-1, n_list, factorials)
    
    def helper(self, n, k, n_list, factorials):
        if n == 1:
            return str(n_list[0])
        
        m = k // factorials[n-1]
        k %= factorials[n-1]     
        res = str(n_list[m])
        n_list.remove(n_list[m])
        res += self.helper(n-1, k, n_list, factorials)
        return res

if __name__ == "__main__":
    n, k = 4, 14
    print(Solution().getPermutation(n, k))