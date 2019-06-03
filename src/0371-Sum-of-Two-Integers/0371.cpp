class Solution 
{
public:
    int getSum(int a, int b) 
    {
        if (!b) return a;
        long long sum = a ^ b, carry = (a & b & 0xffffffff) << 1;
        return getSum(sum, carry);
    }
};