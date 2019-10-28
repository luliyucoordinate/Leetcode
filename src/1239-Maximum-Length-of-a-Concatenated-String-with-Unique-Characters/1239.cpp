class Solution 
{
public:
    typedef bitset<26> charBits;
    int maxLength(vector<string>& arr) 
    {
        dfs(arr, 0, "");
        return res;
    }
private:
    int res = 0;
    
    void dfs(vector<string>& arr, int index, string path)
    {
        auto bp = toBitset(path);
        int lsp = bp.count(), lp = path.size();
        if (lp == lsp) res = max(res, lp);
        if (index == arr.size() || lsp != lp) return;
        for (int i = index; i < arr.size(); i++)
            dfs(arr, i + 1, path + arr[i]);
    }
    
    charBits toBitset(const string& s) 
    {
        charBits bs;
        for (char c : s) bs.set(c - 'a');
        return bs;
    }
};