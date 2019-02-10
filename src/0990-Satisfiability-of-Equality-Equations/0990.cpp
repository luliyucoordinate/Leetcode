static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    bool equationsPossible(vector<string>& equations) 
    {
        for (int i = 0; i < 26; ++i) _parents[i] = i;
        for (string& e : equations)
        {
            if (e[1] == '=')
                _parents[_find(e[0] - 'a')] = _find(e[3] - 'a');
        }
            
        for (string& e : equations)
        {
            if (e[1] == '!' && _find(e[0] - 'a') == _find(e[3] - 'a'))
                return false;
        }
        return true;       
    }
private:
    int _parents[26];

    int _find(int x) 
    {
        if (x != _parents[x]) _parents[x] = _find(_parents[x]);
        return _parents[x];
    }
};