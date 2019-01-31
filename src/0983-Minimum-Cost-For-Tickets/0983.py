class Solution:
    def mincostTickets(self, days: 'List[int]', costs: 'List[int]') -> 'int':
        mem = [0]*31
        days_set = set(days)
        for i in range(1, days[-1]+1):
            if i not in days_set:
                mem[i%31] = mem[(i-1)%31]
            else:
                mem[i%31] = min(mem[(i-1)%31]+costs[0], mem[max(i-7, 0)%31]+costs[1], mem[max(i-30, 0)%31]+costs[2])
                
        return mem[days[-1]%31]