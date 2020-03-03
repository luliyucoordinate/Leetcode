class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        i = j = 0
        
        for x in pushed:
            pushed[i] = x
            i += 1
            while i > 0 and pushed[i - 1] == popped[j]:
                i, j = i - 1, j + 1
            
        return i == 0