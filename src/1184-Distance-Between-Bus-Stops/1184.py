class Solution:
    def distanceBetweenBusStops(self, dis: List[int], l: int, r: int) -> int:
        if l > r:
            l, r = r, l
        k, v = sum(dis[l:r]), sum(dis)
        return min(k, v - k)