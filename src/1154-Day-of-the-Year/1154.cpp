class Solution 
{
public:
    int dayOfYear(string date) 
    {
        int Y = stoi(date.substr(0, 4)), M = stoi(date.substr(5, 2)), D = stoi(date.substr(8));
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31}, res = D;
        if (Y % 400 == 0 or Y % 4 == 0 and Y % 100 != 0) days[1]++;
        for (int i = 0; i < M - 1; ++i) res += days[i];
        return res;
    }
};