class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """    
        res, all_sum, min_sum = -1, 0, float('inf')
        n = len(gas)
        for i in range(n):
            all_sum += gas[i] - cost[i]
            if min_sum > all_sum:
                min_sum = all_sum
                res = (i + 1)%n
                
        if all_sum < 0:
            return -1
        
        return res