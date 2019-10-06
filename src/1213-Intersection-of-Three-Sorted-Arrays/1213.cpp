class Solution
{
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    {
        vector<int> arr12;
        set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(arr12));
        vector<int> res;
        set_intersection(arr12.begin(), arr12.end(), arr3.begin(), arr3.end(), back_inserter(res));
        return res;
    }
};