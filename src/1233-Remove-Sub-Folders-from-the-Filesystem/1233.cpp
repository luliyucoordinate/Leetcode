class Solution 
{
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(), folder.end());
        vector<string> res;
        int l = 2;
        string parent = "";
        for (auto& f : folder)
        {
            if (f.substr(0, l) != parent)
            {
                l = f.size() + 1;
                parent = f + "/";
                res.push_back(f);
            }
        }
        return res;
    }
};