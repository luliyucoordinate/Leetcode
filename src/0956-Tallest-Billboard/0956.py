class Solution:
    def tallestBillboard(self, rods):
        """
        :type rods: List[int]
        :rtype: int
        """
        def helper(A):
            mem = {0: 0}
            for x in A:
                cur = mem.copy()
                for d, y in cur.items():
                    mem[d + x] = max(mem.get(x + d, 0), y)
                    mem[abs(d - x)] = max(mem.get(abs(d - x), 0), y + min(d, x))
            return mem

        mem, mem2 = helper(rods[:len(rods) // 2]), helper(rods[len(rods) // 2:])
        return max(mem[d] + mem2[d] + d for d in mem if d in mem2)