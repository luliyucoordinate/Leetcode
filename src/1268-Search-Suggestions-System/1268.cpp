class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        int l = 0, r = products.size() - 1;
        
        for (int i = 0; i < searchWord.size(); i++)
        {
            while (l <= r && (products[l].size() <= i || products[l][i] != searchWord[i])) l++;
            while (l <= r && (products[r].size() <= i || products[r][i] != searchWord[i])) r--;
            if (l <= r) res.push_back(vector<string>(products.begin() + l, products.begin() + min(l+3, r+1)));
            else res.push_back({});
        }
        return res;
    }
};