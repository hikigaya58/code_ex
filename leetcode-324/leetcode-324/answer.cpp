#include<vector>
#include<algorithm>

using std::nth_element;
using std::vector;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		auto mid_iter = nums.begin() + (nums.size() >> 1);
		nth_element(nums.begin(), mid_iter, nums.end());
		auto mid_num = *mid_iter;

		size_t i = 0, j = 0, k = nums.size() - 1;
		while (j < k) {
			if (nums[j] < mid_num)
				std::swap(nums[i++], nums[j++]);
			else if (nums[j] > mid_num)
				std::swap(nums[j], nums[k--]);
			else
				++j;
		}

		vector<int> ans;
		auto low = nums.rbegin() + ((nums.size() | 1) >> 1), mid = low, high = nums.rbegin();
		while (low < nums.rend()) {
			ans.push_back(*low++);
			if (high < mid)
				ans.push_back(*high++);
		}

		nums = ans;
	}
};