class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        satisfied, max_add_satisfied, add_satisfied = 0, 0, 0
        for i in range(len(customers)):
            satisfied += 0 if grumpy[i] else customers[i]
            add_satisfied += customers[i] if grumpy[i] else 0
            if i >= X:
                add_satisfied -= customers[i - X] if grumpy[i - X] else 0
            max_add_satisfied = max(max_add_satisfied, add_satisfied)
        return satisfied + max_add_satisfied