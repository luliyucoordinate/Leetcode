#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> result;
        for (auto& email : emails)
        {
            auto at_pos = email.find('@');
            auto plus_pos = email.find('+');
            if (plus_pos < at_pos)
            {
                auto len = at_pos - plus_pos;
                email.erase(plus_pos, len);
                at_pos -= len;
            }
            auto dot_pos = email.find('.'); 
            while (dot_pos < at_pos)
            {
                email.erase(dot_pos, 1);
                at_pos--;
                dot_pos = email.find('.');
            }
            result.insert(email);
        }
        return result.size();
    }
};
int main()
{
    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    cout << Solution().numUniqueEmails(emails);
    return 0;
}
