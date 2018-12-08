#include <vector>
#include <algorithm>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
		int n = deck.size();
		vector<int> res(n);
		sort(deck.begin(), deck.end());
		res[n-1] = deck.back();
		for(int i = n - 2; i >= 0; --i)
        {
			res[i] = deck[i];
			rotate(res.begin() + i + 1, res.begin() + n - 1, res.end());
		}
		return res;
	}
};