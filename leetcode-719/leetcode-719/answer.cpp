#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		auto count = [&](int mid) {
			int i = 0, cnt = 0;
			for (int j = 0; j != nums.size(); ++j) {
				while (nums[j] - nums[i] > mid)
					++i;
				cnt += (j - i);
			}
			return cnt;
		};

		int left = 0, right = nums.back() - nums.front();
		while (left <= right) {
			auto mid = (left + right) >> 1;
			if (count(mid) >= k) //因为距离是不连续的，这里是为了找到实际存在的距离
				right = mid - 1;
			else
				left = mid + 1;
		}

		return left;
	}
};