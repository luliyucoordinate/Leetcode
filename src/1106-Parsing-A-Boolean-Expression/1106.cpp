class Solution {
public:
    bool parseBoolExpr(string expression) {
        this->s = expression;
        int i = 0;
        return parseStr(i);
    }
    
    string s;
    bool parseStr(int& i)
    {
        if (s[i] == 't') 
        {
            ++i;
            return true;
        }
        else if (s[i] == 'f')
        {
            ++i;
            return false;
        }
        else if (s[i] == '&') return parseAnd(i);
        else if (s[i] == '|') return parseOr(i);
        else return parseNot(i);
    }
    
    bool parseAnd(int& i)
    {
        i += 2;
        bool res = parseStr(i);
        while (s[i] != ')')
        {
            i++;
            res &= parseStr(i);
        }
        i++;
        return res;
    }
    
    bool parseOr(int& i) 
    {
        i += 2;
        bool res = parseStr(i);
        while (s[i] != ')')
        {
            i++;
            res |= parseStr(i);
        }
        i++;
        return res;
    }
    
    bool parseNot(int& i)
    {
        i += 2;
        bool res = !parseStr(i);
        i++;
        return res;
    }
};