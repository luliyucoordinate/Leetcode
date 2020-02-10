class Solution {
    public double angleClock(int hour, int minutes) {
        double t = Math.abs((hour*30 + minutes/2.0) - minutes*6);
        return Math.min(t, 360 - t);
    }
}