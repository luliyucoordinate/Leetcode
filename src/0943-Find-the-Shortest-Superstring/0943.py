class Solution:
    def shortestSuperstring(self, A):
        """
        :type A: List[str]
        :rtype: str
        """
        def findOverlappingPair(s1, s2):
            max_overlap_len = float("-inf") 
            n = min(len(s1), len(s2))
            res = ''
            for i in range(1, n + 1):
                if s1.endswith(s2[:i]):
                    if max_overlap_len < i:
                        max_overlap_len = i
                        res = s1 + s2[i:]
            for i in range(1, n + 1):
                if s2.endswith(s1[:i]):
                    if max_overlap_len < i:
                        max_overlap_len = i
                        res = s2 + s1[i:]

            return max_overlap_len, res
        
        A_len = len(A)
        
        while A_len != 1:
            p, q = -1, -1
            res = ''
            max_len = float("-inf") 
            for i in range(A_len):
                for j in range(i+1, A_len):
                    overlap_len, tmp_res = findOverlappingPair(A[i], A[j])
                    if max_len < overlap_len:
                        max_len = overlap_len
                        res = tmp_res
                        p = j
                        q = i
            A_len -= 1
            if max_len == float("-inf"): 
                A[0] = A[0] + A[A_len]
            else:
                A[p] = res
                A[q] = A[A_len]
            
        return A[0]
            
        
if __name__ == "__main__":
    A = ["catg","ctaagt","gcta","ttca","atgcatc"]
    print(Solution().shortestSuperstring(A))