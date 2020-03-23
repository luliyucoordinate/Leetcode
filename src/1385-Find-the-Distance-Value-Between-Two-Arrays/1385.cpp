class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        
        int res = 0;
        this->d = d;
        for (int x : arr1) {
            if (check(arr2, x)) res++;
        }
        return res;
    }
private:
    int d;
    
    bool check(vector<int>& arr2, int x) {
        int l = 0, r = arr2.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (abs(arr2[mid] - x) <= d) return false;
            if (arr2[mid] > x) r = mid;
            else l = mid + 1;
        }
        return abs(arr2[l] - x) > d;
    }
};