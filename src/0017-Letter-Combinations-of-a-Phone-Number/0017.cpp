#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        if (digits.empty()) return result;
        findCombination(digits, 0, string(""), result);
        return result;
    }
private:
    const vector<string> letterMap = {            
                        " ","","abc",
                        "def","ghi","jkl",
                        "mno","pqrs","tuv","wxyz"};

    void findCombination(const string& digits, int index, const string& s, vector<string>& res)
    {
        if (digits.length() == index) 
        {
            res.push_back(s);
            return;
        }
        char ch = digits[index];
        string letters = letterMap[ch - '0'];
        for (auto& letter : letters)
        {
            findCombination(digits, index + 1, s + letter, res);
        }
    }
};