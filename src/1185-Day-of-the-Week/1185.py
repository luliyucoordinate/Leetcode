import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        return ("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday")[datetime.date(year, month, day).weekday()]