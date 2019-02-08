class Solution:
    def countTriplets(self, A: 'List[int]') -> 'int':
        arr = [0]*(1 << 16)
        mask = (1 << 16) - 1
        for a in A:
            k = mask ^ a
            i = k
            while i:
                arr[i ^ a] += 1
                i = (i - 1) & k
            else:
                arr[i ^ a] += 1
                
        res = 0
        for a in A:
            for b in A:
                res += arr[mask ^ (a & b)]
        
        return res