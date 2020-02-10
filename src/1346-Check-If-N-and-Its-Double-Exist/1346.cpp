class Solution 
{
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_set<int> seen;
        for (int i : arr)
        {
            if (seen.count(2*i) || (i % 2 == 0 && seen.count(i / 2))) return true;
            seen.insert(i);
        }
        return false;
    }
};