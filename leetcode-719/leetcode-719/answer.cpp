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
			if (count(mid) >= k) //��Ϊ�����ǲ������ģ�������Ϊ���ҵ�ʵ�ʴ��ڵľ���
				right = mid - 1;
			else
				left = mid + 1;
		}

		return left;
	}
};