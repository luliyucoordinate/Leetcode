var dayOfTheWeek = function(d, m, y) {
    var weeks = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    if (m < 3) {
        m += 12; y--;
    }
    return weeks[(d+2*m+Math.floor(3*(m+1)/5)+y+Math.floor(y/4)-Math.floor(y/100)+Math.floor(y/400)+1)%7];
};