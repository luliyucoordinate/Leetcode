#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        for (auto& token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                if (token == "+") st.push(top2 + top1);
                else if (token == "-") st.push(top2 - top1);
                else if (token == "*") st.push(top2 * top1);
                else if (token == "/") st.push(top2 / top1);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
int main()
{
    vector<string> str = {"2", "1", "+", "3", "*"};
    cout << Solution().evalRPN(str) << endl;
    return 0;
}