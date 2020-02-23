var daysBetweenDates = function(date1, date2) {
    let days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    
    let check = function(y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); 
    }
    
    let daysFrom1971 = function(dt) {
        let y = Number(dt.substring(0, 4)), m = Number(dt.substring(5, 7)), d = Number(dt.substring(8));
        for (let i = 1971; i < y; ++i) d += check(i) ? 366 : 365;
        for (let i = 0; i < m - 1; i++) d += days[i];
        if (m > 2 && check(y)) d++;
        return d;
    }  
    return Math.abs(daysFrom1971(date1) - daysFrom1971(date2));
};