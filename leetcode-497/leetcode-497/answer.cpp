#include<vector>
#include<random>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	Solution(vector<vector<int>>& rects) :_rects(rects) {
		for (auto& rect : rects)
			sum.push_back(sum.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
	}

	vector<int> pick() {
		static default_random_engine e;
		uniform_int_distribution<unsigned> distri(0, sum.back() - 1);

		auto rand = distri(e);
		auto it = upper_bound(sum.begin(), sum.end(), rand) - 1;
		auto offset = rand - (*it);
		auto index = it - sum.begin();
		auto& rect = _rects[index];
		int x = rect[0] + offset % (rect[2] - rect[0] + 1);
		int y = rect[1] + floor(offset / (rect[2] - rect[0] + 1));

		return vector<int>{x, y};
	}

private:
	vector<vector<int>> _rects;
	vector<int> sum{ 0 };
};
