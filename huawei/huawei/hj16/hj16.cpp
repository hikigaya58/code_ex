#include <iostream>
#include <vector>
#include <unordered_map>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
	//read input
	int num_money, num_all;
	cin >> num_money >> num_all;

	unordered_map<int, deque<vector<int>>> relationship;

	for (int i = 0; i != num_all; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (c == 0) {
			if (relationship.count(i + 1))
				relationship[i + 1].push_front(vector<int>{a, b});
			else
				relationship[i + 1] = deque<vector<int>>{ vector<int>{a,b} };
		}
		else
		{
			if (relationship.count(c))
				relationship[c].push_back(vector<int>{a, b});
			else
				relationship[c] = deque<vector<int>>{ vector<int>{a,b} };
		}
	}

	//generate statify and value array
	vector<vector<int>> num_statify;
	vector<vector<int>> num_value;
	for (auto i = relationship.cbegin(); i != relationship.cend(); ++i) {
		auto& a = i->second;
		//cout << a.size();
		switch (a.size())
		{
		case 1:
			num_statify.push_back(vector<int>{a[0][0] * a[0][1]});
			num_value.push_back(vector<int>{a[0][0]});
			break;
		case 2:
			num_statify.push_back(vector<int>{a[0][0] * a[0][1], a[0][0] * a[0][1] + a[1][0] * a[1][1]});
			num_value.push_back(vector<int>{a[0][0], a[0][0] + a[1][0]});
			break;
		case 3:
			num_statify.push_back(vector<int>{a[0][0] * a[0][1],
				a[0][0] * a[0][1] + a[1][0] * a[1][1],
				a[0][0] * a[0][1] + a[2][0] * a[2][1],
				a[0][0] * a[0][1] + a[1][0] * a[1][1] + a[2][0] * a[2][1]
			});
			num_value.push_back(vector<int>{a[0][0], a[0][0] + a[1][0], a[0][0] + a[2][0], a[0][0] + a[1][0] + a[2][0]});
			break;
		default:
			cout << "something error" << endl;
			break;
		}

	}

	//dynamic programming
	vector<int> dp(1 + num_money / 10, 0);
	for (int i = 0; i != num_statify.size(); ++i) {
		for (int j = dp.size() - 1; j != 0; --j) {
			int temp = dp[j];
			for (int k = 0; k != num_statify[i].size(); ++k)
				if (j * 10 >= num_value[i][k])
					temp = max(temp, dp[(j * 10 - num_value[i][k]) / 10] + num_statify[i][k]);
			dp[j] = temp;
		}
	}
	cout << dp.back();
	return 0;
}