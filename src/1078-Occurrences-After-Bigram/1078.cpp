class Solution 
{
public:
    vector<string> findOcurrences(string text, string first, string second) 
    {
        vector<string> res;
        stringstream ss(text);
        string word, pre, cur;
        while (ss >> word) 
        {
            if (pre == first and cur == second) 
            {   
                res.push_back(word);
            }
            pre = cur ;
            cur = word;
        }
        return res;
    }
};