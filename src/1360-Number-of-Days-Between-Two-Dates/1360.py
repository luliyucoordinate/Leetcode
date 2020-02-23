class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        days = [31,28,31,30,31,30,31,31,30,31,30,31]
        def check(Y):
            return Y % 4 == 0 and (Y % 100 != 0 or Y % 400 == 0)
        
        def days_from_1971(date):
            Y, M, D = list(map(int, date.split("-")))
            
            for i in range(1971, Y):
                D += 366 if check(i) else 365
            return D + (M > 2 and check(Y)) + sum(days[:M - 1])
        return abs(days_from_1971(date1) - days_from_1971(date2))