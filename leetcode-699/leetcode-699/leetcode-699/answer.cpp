#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> fallingSquares(vector<vector<int>>& positions) {
		map<int, int> rangeHeights{ {0,0} };
		vector<int> ans{ 0 };

		for (auto& position : positions) {
			int size = position[1];
			int left = position[0], right = left + size - 1;
			auto it_left = rangeHeights.lower_bound(left),
				it_right = rangeHeights.upper_bound(right);

			int maxHeight = size;
			for (auto it = it_left; it != it_right; ++it) {
				maxHeight = max(maxHeight, size + (it->second));
			}
			rangeHeights.erase(it_left, it_right);
			rangeHeights[left] = maxHeight;

			ans.push_back(max(ans.back(), maxHeight));
		}

		return vector<int>(ans.begin() + 1, ans.end());
	}
};