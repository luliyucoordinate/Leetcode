class Solution 
{
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        unordered_map<int, int> st;
        vector<int> arrs(arr);
        sort(arrs.begin(), arrs.end());
        
        for (int i = 0; i < arrs.size(); i++)
        {
            st.emplace(arrs[i], st.size() + 1);
        }
        
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = st[arr[i]];
        }
        return arr;
    }
};