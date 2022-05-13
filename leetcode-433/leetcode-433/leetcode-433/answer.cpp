#include<vector>
#include<string>
#include<unordered_set>
#include<deque>

using namespace std;

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {

		auto bankSize = bank.size();
		vector<vector<int>> adj(bankSize);
		auto diffOne = [](string s1, string s2) -> int {
			auto diff = 0;
			for (auto i = s1.cbegin(), j = s2.cbegin(); i != s1.cend(); ++i, ++j)
				if (*i != *j) {
					++diff;
					if (diff > 1)
						return diff;
				}
			return diff;
		};

		for (int i = 0; i != bankSize; ++i)
			for (int j = i + 1; j < bankSize; ++j)
				if (diffOne(bank[i], bank[j]) == 1) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}

		unordered_set<int> visited;
		deque<int> remains;
		for (auto i = bank.cbegin(); i != bank.cend(); ++i)
			if (diffOne(*i, start) == 1)
				remains.push_back(i - bank.cbegin());

		int step = 1;
		while (!remains.empty()) {
			int tmp = remains.size();
			for (int i = 0; i != tmp; ++i) {
				int curr = remains.front();
				remains.pop_front();
				visited.insert(curr);
				if (bank[curr] == end)
					return step;
				for (auto i : adj[curr])
					if (visited.count(i) == 0)
						remains.push_back(i);
			}
			++step;
		}
		return -1;
	}
};