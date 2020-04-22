class Solution {
public:
	int minNumberOfFrogs(string cr) {
		int c = 0, r = 0, a = 0, k = 0, o = 0, frogs = 0, res = 0;
		for(char i : cr) {
			if (i=='c') {c++; frogs++;}
			else if (i=='r') r++; 
			else if (i=='o') o++; 
			else if (i=='a') a++; 
			else {k++; frogs--;}
			res = max(res, frogs);
			if (c < r || r < o || o < a || a < k) return -1;    
		}
		if (c == r && c == o && c == a && c == k) return res;
		return -1;
	}
};