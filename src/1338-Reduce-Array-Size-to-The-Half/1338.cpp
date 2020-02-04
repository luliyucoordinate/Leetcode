class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        int n = arr.size()/2, total = 0, res = 0;
        unordered_map<int, int> freq;
        map<int, int, greater<int>> cnt;
        for (int i : arr) freq[i]++;
        for (auto& [k, v] : freq) cnt[v]++;
        
        for (auto& [i, v] : cnt)
        {
            int dif = n - total;
            int x = min(cnt[i], (dif + i - 1)/i);
            res += x;
            total += x * i;
            if (total >= n) return res;
        }
        return res;
    }
};