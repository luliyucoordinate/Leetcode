class Solution 
{
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> res;
        int carry = 0, l1 = arr1.size(), l2 = arr2.size();
        while (carry or l1 or l2) 
        {
            if (l1) carry += arr1[--l1];
            if (l2) carry += arr2[--l2];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 and res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};