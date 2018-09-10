#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> mystack;
        unordered_map<char, char> match = {{'(',')'}, {'{','}'}, {'[',']'}};
        for (auto& i : s)
        {
            if (i == '(' || i == '{' || i == '[')
            {
                mystack.push(i);
            }
            else
            {
                if (mystack.empty()) return false;
                char top = mystack.top();
                mystack.pop();
                if (match[top] != i) return false;
            }
        }
        
        return mystack.size() == 0;
    }
};
int main()
{
    string str = "()";
    cout << Solution().isValid(str) << endl;
    return 0;
}