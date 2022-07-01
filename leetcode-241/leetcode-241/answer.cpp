#include<vector>
#include<string>
#include<cctype>

using std::vector;
using std::string;

class Solution {
public:
	vector<int> diffWaysToCompute(string expression) {
		vector<int> ops;
		{
			size_t prev = 0;
			for (size_t i = 0; i != expression.size(); ++i) {
				if (isdigit(expression[i]) > 0)
					continue;
				if (ispunct(expression[i])) {
					ops.push_back(stoi(expression.substr(prev, i - prev)));
					if (expression[i] == '+')
						ops.push_back(-1);
					else if (expression[i] == '-')
						ops.push_back(-2);
					else
						ops.push_back(-3);
					prev = i + 1;
				}
			}
			ops.push_back(stoi(expression.substr(prev)));
		}

		vector<vector<vector<int>>> dp(ops.size(), vector<vector<int>>(ops.size(), vector<int>{}));
		for (size_t i = 0; i < ops.size(); i += 2)
			dp[i][i].push_back(ops[i]);

		for (size_t size = 3; size < ops.size() + 1; size += 2) {
			for (size_t right = size - 1; right < ops.size(); ++right) {
				auto left = right - size + 1;
				for (size_t op = left + 1; op < right; op += 2) {
					for (auto& a : dp[left][op - 1]) {
						for (auto& b : dp[op + 1][right]) {
							if (ops[op] == -1)
								dp[left][right].push_back(a + b);
							else if (ops[op] == -2)
								dp[left][right].push_back(a - b);
							else
								dp[left][right].push_back(a * b);
						}
					}
				}
			}
		}

		return dp[0][ops.size() - 1];
	}
};