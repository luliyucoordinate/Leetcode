class NumArray:
    def __init__(self, nums: 'List[int]'):
        self.nums = nums
        self.tree = [0]*(len(nums) + 1)
        for i in range(len(nums)):
            self._update(i+1, nums[i])
            
    def _update(self, i, delta):
        while i < len(self.tree):
            self.tree[i] += delta
            i += self.lowbit(i)
    
    def query(self, i):
        res = 0
        while i:
            res += self.tree[i]
            i -= self.lowbit(i)
        return res
            
    def lowbit(self, x):
        return x & (-x)

    def update(self, i: 'int', val: 'int') -> 'None':
        self._update(i+1, val - self.nums[i])
        self.nums[i] = val

    def sumRange(self, i: 'int', j: 'int') -> 'int':
        return self.query(j+1) - self.query(i)

if __name__ == "__main__":
    nums = [0,9,5,7,3]
    a = NumArray(nums)
    print(a.sumRange(4, 4))
    print(a.sumRange(2, 4))