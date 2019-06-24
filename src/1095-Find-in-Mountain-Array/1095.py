class Solution:
    def findInMountainArray(self, t: int, m: 'MountainArray') -> int:
        p, r = 0, m.length() - 1
        while p < r:
            mid = (p + r) >> 1
            if m.get(mid) > m.get(mid + 1):
                r = mid
            else:
                p = mid + 1

        i = self.bs(m, t, 0, p, True)
        if i != -1:
            return i
        else:
            return self.bs(m, t, p+1, m.length()-1, False)
        
    def bs(self, m, t, l, r, asc):
        while l < r:
            mid = (l + r + 1) >> 1
            if (asc and m.get(mid) <= t) or (not asc and m.get(mid) >= t):
                l = mid
            else:
                r = mid - 1
        if m.get(l) == t:
            return l
        return -1