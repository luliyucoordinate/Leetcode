class Solution {
public:
    string reformat(string s) {
        stringstream schars, snums;
        for (char c : s) {
            if (c >= '0' && c <= '9') snums << c;
            else schars << c;
        }
        
        string chars = schars.str(), nums = snums.str();
        if (abs(int(chars.size() - nums.size())) > 1) return "";
        stringstream res;
        
        bool flag = nums.size() >= chars.size() ? true : false;
        for (int i = 0; i < s.size(); i++) {
            if (flag) {
                res << nums.back();
                nums.pop_back();
            } else {
                res << chars.back();
                chars.pop_back();
            }
            flag = !flag;
        }
        return res.str();
    }
};