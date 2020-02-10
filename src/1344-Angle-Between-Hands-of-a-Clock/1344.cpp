class Solution 
{
public:
    double angleClock(int hour, int minutes) 
    {
        double t = abs((hour*30 + minutes/2.0) - minutes*6);
        return min(t, 360 - t);
    }
};