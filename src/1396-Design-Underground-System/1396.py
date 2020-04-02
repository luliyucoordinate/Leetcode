class UndergroundSystem:

    def __init__(self):
        self.check_in = collections.defaultdict(list)
        self.check_out = collections.defaultdict(list)


    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.check_in[id] = [stationName, t]


    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startName, timeIn = self.check_in[id]
        name = startName + ">" + stationName
        if not self.check_out[name]: 
            self.check_out[name] = [0, 0]
        self.check_out[name][0] += t - timeIn
        self.check_out[name][1] += 1


    def getAverageTime(self, startStation: str, endStation: str) -> float:
        name = startStation + ">" + endStation
        return self.check_out[name][0] / self.check_out[name][1]