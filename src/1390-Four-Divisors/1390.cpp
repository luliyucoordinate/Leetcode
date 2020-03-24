class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int num : nums) res += get_divisors(num);
        return res;
    }
    
    int get_divisors(int x) {
        int res = 0, cnt = 0;
        for (int i = 1; i * i <= x; i ++ ) {
            if (x % i == 0) {
                res += i; cnt++;
                if (i * i != x) {
                    res += x / i;
                    cnt++;
                }
                if (cnt > 4) return 0;
            }
        }
        return cnt < 4 ? 0 : res;
    }
};