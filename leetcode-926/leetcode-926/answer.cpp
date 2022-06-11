#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	int minFlipsMonoIncr(string s) {
		auto dp0 = 0, dp1 = 0;
		for (auto& ch : s) {
			dp1 = min(dp0, dp1) + (ch == '0' ? 1 : 0);
			dp0 = dp0 + (ch == '0' ? 0 : 1);
		}
		return min(dp0, dp1);
	}
};