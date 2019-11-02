class Solution 
{
public:
    string toGoatLatin(string S) 
    {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        stringstream in(S);
        string res, w;
        int i = 0, j;
        while (in >> w) 
        {
            res += ' ' + (vowel.count(w[0]) ? w : w.substr(1) + w[0]) + "ma";
            res += string(++i, 'a');
        }
        return res.substr(1);
    }
};