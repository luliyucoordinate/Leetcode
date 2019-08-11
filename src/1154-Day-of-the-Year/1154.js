var dayOfYear = function(date) {
    var date = date.split("-");
    var Y = Number(date[0]), M = Number(date[1]) - 1;
    var days = [31,28,31,30,31,30,31,31,30,31,30,31], res = Number(date[2]);
    if (Y % 400 == 0 || Y % 4 == 0 && Y % 100 != 0) days[1]++;
    for (var i = 0; i < M; ++i) res += days[i];
    return res;
};