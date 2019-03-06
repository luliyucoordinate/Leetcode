class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        d = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        tmp = res = 0
        x, y = 0, 0
        ob = set(map(tuple, obstacles))
        for i in commands:
            if i == -1:
                tmp += 1
            elif i == -2:
                tmp -= 1
            else:
                for _ in range(i):
                    x += d[tmp%4][0]
                    y += d[tmp%4][1]
                    if (x, y) in ob:
                        x -= d[tmp%4][0]
                        y -= d[tmp%4][1]
            res = max(res, x**2 + y**2)
        return res