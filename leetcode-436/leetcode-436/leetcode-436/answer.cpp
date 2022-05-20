#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		map<int, int> valIndexMap;
		for (int i = 0; i != intervals.size(); ++i) {
			if (valIndexMap.count(intervals[i][0]))
				continue;
			valIndexMap.insert({ intervals[i][0], i });
		}

		vector<int> answer;
		for (int i = 0; i != intervals.size(); ++i) {
			auto it = valIndexMap.lower_bound(intervals[i][1]);
			if (it != valIndexMap.end()) {
				answer.push_back(it->second);
				continue;
			}
			answer.push_back(-1);
		}

		return answer;
	}
};