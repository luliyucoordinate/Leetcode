class RecentCounter:
    def __init__(self):
        self.pings = list()       

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.pings.append(t)
        while self.pings[0] < t - 3000:
            self.pings.pop(0)
        return len(self.pings)