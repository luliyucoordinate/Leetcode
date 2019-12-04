class Solution(object):
    def countShips(self, sea: 'Sea', tp: 'Point', lp: 'Point') -> int:
        if lp.x > tp.x or lp.y > tp.y or not sea.hasShips(tp, lp):
            return 0
        if tp.x == lp.x and tp.y == lp.y:
            return 1
        nx, ny = (tp.x + lp.x)//2, (tp.y + lp.y)//2
        return self.countShips(sea, Point(nx, tp.y), Point(lp.x, ny + 1)) +\
            self.countShips(sea, Point(nx, ny), lp) + \
            self.countShips(sea, tp, Point(nx + 1, ny + 1)) + \
            self.countShips(sea, Point(tp.x, ny), Point(nx + 1, lp.y))