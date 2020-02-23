class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(daysFrom1971(date1) - daysFrom1971(date2));
    }
    
    private int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    private boolean check(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); 
    }
    
    private int daysFrom1971(String dt) {
        int y = Integer.parseInt(dt.substring(0, 4)), m = Integer.parseInt(dt.substring(5, 7)), d = Integer.parseInt(dt.substring(8));
        for (int i = 1971; i < y; ++i) d += check(i) ? 366 : 365;
        for (int i = 0; i < m - 1; i++) d += days[i];
        if (m > 2 && check(y)) d++;
        return d;
    }  
}