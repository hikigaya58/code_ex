#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		if (accumulate(matchsticks.begin(), matchsticks.end(), 0) % 4 != 0)
			return false;

		vector<int> dp(1 << matchsticks.size(), -1);
		dp[0] = 0;
		int size = accumulate(matchsticks.begin(), matchsticks.end(), 0) / 4;

		for (long i = 1; i < 1 << matchsticks.size(); ++i)
			for (int j = 0; j < matchsticks.size(); ++j) {
				if ((i & (1 << j)) == 0)
					continue;
				auto s = i & ~(1 << j);
				if (dp[s] >= 0 && dp[s] + matchsticks[j] <= size) {
					dp[i] = (dp[s] + matchsticks[j]) % size;
					break;
				}
			}

		return dp.back() == 0;
	}
};