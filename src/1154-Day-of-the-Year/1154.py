import datetime
class Solution:
    def dayOfYear(self, date: str) -> int:
        Y, M, D = list(map(int, date.split("-")))
        return int(datetime.date(Y, M, D).strftime("%j"))