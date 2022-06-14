#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int countPalindromicSubsequences(string s) {
		int mod = 1e9 + 7;

		auto n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i != n; ++i)
			dp[i][i] = 1;

		vector<vector<int>> prev(n, vector<int>(4, 0));
		auto next = prev;
		{
			vector<int> tmp(4, -1);
			for (int i = 0; i != n; ++i) {
				for (int j = 0; j != 4; ++j)
					prev[i][j] = tmp[j];
				tmp[s[i] - 'a'] = i;
			}

			vector<int> tmp2(4, n);
			for (int i = n - 1; i >= 0; --i) {
				for (int j = 0; j != 4; ++j)
					next[i][j] = tmp2[j];
				tmp2[s[i] - 'a'] = i;
			}
		}

		for (int size = 2; size != n + 1; ++size)
			for (int head = 0; head + size <= n; ++head) {
				int tail = head + size - 1;
				if (s[head] == s[tail]) {
					auto low = next[head][s[head] - 'a'];
					auto high = prev[tail][s[head] - 'a'];
					if (low > high)
						dp[head][tail] = (2 + dp[head + 1][tail - 1] * 2) % mod;
					else if (low == high)
						dp[head][tail] = (1 + dp[head + 1][tail - 1] * 2) % mod;
					else if (low < high)
						dp[head][tail] = (0LL + mod + dp[head + 1][tail - 1] * 2 - dp[low + 1][high - 1]) % mod;
				}
				else
					dp[head][tail] = (0LL + mod + dp[head + 1][tail] + dp[head][tail - 1] - dp[head + 1][tail - 1]) % mod;
			}

		return dp[0][n - 1];
	}
};