class Solution 
{
public:
    int digitsCount(int d, int low, int high) 
    {
        return digitCounts(d, high) - digitCounts(d, low-1);
    }
private:
    int digitCounts(int k, int n) 
    {
        int base = 1, cnt = 0;
        while (n / base >= 1)
        {
            int cur = n / base % 10;
            int l = n % base;
            int h = n / (base*10);
            if (cur == k) 
            {
                if (k == 0) cnt += (h - 1) * base + l + 1;
                else cnt += 1 + base * h + l;
            }
            else if (cur < k) cnt += base * h;
            else 
            {
                if (k == 0) cnt += base * h;
                else cnt += base * (h + 1);
            }
            base *= 10;
        }
        return cnt;
    }
};