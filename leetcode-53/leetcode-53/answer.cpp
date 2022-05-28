#include<vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int pre = 0, ans = nums.front();
		for (auto& i : nums) {
			pre = max(pre + i, i);
			ans = max(pre, ans);
		}
		return ans;
	}
};