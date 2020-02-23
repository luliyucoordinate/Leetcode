class Solution 
{
public:
    int daysBetweenDates(string date1, string date2) 
    {
        return abs(daysFrom1971(date1) - daysFrom1971(date2));
    }
private:
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool check(int y) 
    { 
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); 
    }
    
    int daysFrom1971(string dt) 
    {
        int y = stoi(dt.substr(0, 4)), m = stoi(dt.substr(5, 2)), d = stoi(dt.substr(8));
        for (int i = 1971; i < y; ++i) d += check(i) ? 366 : 365;
        return d + (m > 2 && check(y)) + accumulate(begin(days), begin(days) + m - 1, 0);
    }  
};