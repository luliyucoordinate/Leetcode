class Solution:
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        box, result, max_A = [0]*40000, 0, 0
        for a in A:
            box[a] += 1
            if max_A < a:
                max_A = a
                
        for i in range(max_A):
            if box[i] <= 1:
                continue
            ano = box[i] - 1
            result += ano
            box[i+1] += ano
            box[i] = 1
   
        last_ano = box[max_A] - 1
        result += (1 + last_ano)*last_ano//2
        return result